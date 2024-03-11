#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_search_tree.h"

void bst_init(BinarySearchTree *bst)
{
    bst->root = NULL;
}

Node _bst_make_new_node(Key key, Data data)
{
    Node new_node = NULL;
    new_node = (Node)malloc(sizeof(BinarySearchTree));
    if (new_node == NULL)
    {
        printf(" (!) Memory allocation failed!\n");
        return NULL;
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void bst_get_node_data(Node x, void (*print_data_function)(Data))
{
    if (x != NULL)
    {
        print_data_function(x->data);
    }
    else
    {
        printf(" (!) No data\n");
    }
}

void bst_inorder_tree_walk(Node x, void (*print_data_function)(Data))
{
    if (x != NULL)
    {
        bst_inorder_tree_walk(x->left, print_data_function);
        bst_get_node_data(x, print_data_function);
        bst_inorder_tree_walk(x->right, print_data_function);
    }
}

void bst_preorder_tree_walk(Node x, void (*print_data_function)(Data))
{
    if (x != NULL)
    {
        bst_get_node_data(x, print_data_function);
        bst_preorder_tree_walk(x->left, print_data_function);
        bst_preorder_tree_walk(x->right, print_data_function);
    }
}

void bst_postorder_tree_walk(Node x, void (*print_data_function)(Data))
{
    if (x != NULL)
    {
        bst_postorder_tree_walk(x->left, print_data_function);
        bst_postorder_tree_walk(x->right, print_data_function);
        bst_get_node_data(x, print_data_function);
    }
}

Node bst_tree_search(Node x, Key k, int (*compare_key)(const Key a, const Key b))
{
    if ((x == NULL) || (compare_key(k, x->key) == 0))
        return x;
    if (compare_key(k, x->key) < 0)
        return bst_tree_search(x->left, k, compare_key);
    else
        return bst_tree_search(x-> right, k, compare_key);
}

Node bst_iterative_tree_search(Node x, Key k, int (*compare_key)(const Key a, const Key b))
{
    while (x != NULL && (compare_key(k, x->key) == 0))
    {
        if (compare_key(k, x->key) < 0)
            x = x->left;
        else
            x = x->right;
    }
    return x;
}

Node bst_tree_minimum(Node x, int (*compare_key)(const Key a, const Key b))
{
    while (x->left != NULL)
        x = x->left;
    return x;
}

Node bst_tree_maximum(Node x, int (*compare_key)(const Key a, const Key b))
{
    while (x->right != NULL)
        x = x->right;
    return x;
}