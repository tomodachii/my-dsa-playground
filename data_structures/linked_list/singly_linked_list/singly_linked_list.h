#include <stdio.h>

// Define a type alias for void* with a different name
typedef void *Data;

// Define the structure for a singly linked list
typedef struct SinglyLinkedList
{
  Data data;
  struct SinglyLinkedList *next;
} SinglyLinkedList;

typedef SinglyLinkedList *Node;

Node _sll_make_new_node(Data data);
void _sll_get_node_data(Node node, void (*print_data_function)(Data));
// void sll_free(Node head);
SinglyLinkedList *sll_print(Node head, void (*print_data_function)(Data));
SinglyLinkedList *sll_prepend(Node *head, Data data);
