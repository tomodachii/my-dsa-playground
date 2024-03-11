/**
 * @file binary_search_tree.h
 * @brief Binary Search Tree Implementation
 *
 * This file provides the implementation of a binary search tree in C.
 *
 * @author tomodachii
 */

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

/**
 * Satellite data type
 *
 * @note
 * Defines a type alias for void* with a different name. This typedef allows for a
 * more descriptive name to be used for pointers that can point to any data type.
 */
typedef void *Data;

/**
 * Generic Key type
 *
 * @note
 * Defines a type alias for void* with a different name. This typedef allows for a
 * generic Key type. The key could be integer, character, float ...
 */
typedef void *Key;

typedef struct BinarySearchTreeNode
{
    Key key;                                   /**< Pointer to the key */
    Data data;                                 /**< Pointer to the satellite data stored in the node */
    struct BinarySearchTreeNode *left, *right; /**< Pointer to the next node in the list */
} BinarySearchTreeNode;

/**
 * A node in binary search tree
 * 
 * @note
 * Defines a type alias for a pointer to a BinarySearchTreeNode structure. 
 * This typedef allows for a more convenient way to refer to pointers to nodes
 * in the binary search tree.
 */
typedef BinarySearchTreeNode *Node;

typedef struct BinarySearchTree
{
  Node root; /**< Pointer to the root node of the binary search tree */
} BinarySearchTree;


Node _bst_make_new_node(Key key, Data data);
void bst_init(BinarySearchTree *bst);
void bst_get_node_data(Node node, void (*print_data_function)(Data));
void bst_inorder_tree_walk(Node x, void (*print_data_function)(Data));
void bst_preorder_tree_walk(Node x, void (*print_data_function)(Data));
void bst_postorder_tree_walk(Node x, void (*print_data_function)(Data));
Node bst_tree_search(Node x, Key k, int (*compare_key)(const Key a, const Key b));
Node bst_iterative_tree_search(Node x, Key k, int (*compare_key)(const Key a, const Key b));
Node bst_tree_minimum(Node x, int (*compare_key)(const Key a, const Key b));
Node bst_tree_maximum(Node x, int (*compare_key)(const Key a, const Key b));

#endif /* BINARY_SEARCH_TREE_H */