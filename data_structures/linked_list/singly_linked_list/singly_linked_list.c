#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "singly_linked_list.h"

// if we pass list instead of the SinglyLinkedList pointer *list, the list.head = NULL; will not set the head of the list to NULL since it is passed by value
void sll_init(SinglyLinkedList *list)
{
  list->head = NULL;
}

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
  if (node != NULL) {
    print_data_function(node->data);
  } else {
    printf(" (!) No data\n");
  }
}

void sll_print(SinglyLinkedList list, void (*print_data_function)(Data))
{
  int num = 1;
  Node temp = NULL;
  temp = list.head;
  while (temp != NULL)
  {
    sll_get_node_data(temp, print_data_function);
    temp = temp->next;
    num++;
  }
}

Node sll_prepend(SinglyLinkedList *list, Data data)
{
  Node new_node = _sll_make_new_node(data);
  if (list->head == NULL)
  {
    list->head = new_node;
  }
  else
  {
    new_node->next = list->head;
    list->head = new_node;
  }
  return list->head;
}

Node sll_search(SinglyLinkedList list, Data searchData, int (*compare)(const Data a, const Data b))
{
  Node current = list.head;
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

void sll_delete(SinglyLinkedList *list, Node targetNode)
{
  Node current = list->head;
  Node previous = NULL;

  // Traverse the list to find the node to delete
  while (current != NULL)
  {
    if (current == targetNode)
    {
      printf("found!\n");
      // Found the node to delete
      if (previous == NULL)
      {
        // If the node to delete is the head, update the head
        list->head = current->next;
      }
      else
      {
        // If the node to delete is not the head, bypass it
        previous->next = current->next;
      }

      free(current); // Free the memory of the deleted node
      return;
    }
    previous = current;
    current = current->next;
  }
}
