#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "singly_linked_list.h"

Node _sll_make_new_node(Data data)
{
  Node new_node = NULL;
  new_node = (Node)malloc(sizeof(SinglyLinkedList));
  if (new_node == NULL)
  {
    printf(" (!) Memory allocation failed!\n");
    return NULL;
  }
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

void sll_get_node_data(Node node, void (*print_data_function)(Data))
{
  print_data_function(node->data);
}

SinglyLinkedList *sll_print(Node head, void (*print_data_function)(Data))
{
  int num = 1;
  Node temp = NULL;
  temp = head;
  while (temp != NULL)
  {
    print_data_function(temp->data);
    temp = temp->next;
    num++;
  }
}

SinglyLinkedList *sll_prepend(Node *head, Data data)
{
  Node new_node = _sll_make_new_node(data);
  if (*head == NULL)
  {
    *head = new_node;
  }
  else
  {
    new_node->next = *head;
    *head = new_node;
  }
  return *head;
}

SinglyLinkedList *sll_search(Node head, Data searchData, int (*compare)(const Data a, const Data b))
{
  Node current = head;
  while (current != NULL)
  {
    if (compare(current->data, searchData))
    {
      return current;
    }
    current = current->next;
  }
  return NULL;
}
