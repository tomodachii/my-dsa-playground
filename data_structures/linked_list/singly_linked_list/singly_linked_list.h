#include <stdio.h>

// Define a type alias for void* with a different name
typedef void *Data;

// Define the structure for a singly linked list
typedef struct SinglyLinkedListNode
{
  Data data;
  struct SinglyLinkedListNode *next;
} SinglyLinkedListNode;

typedef SinglyLinkedListNode *Node;

typedef struct SinglyLinkedList
{
  Node head;
} SinglyLinkedList;

Node _sll_make_new_node(Data data);
void sll_init(SinglyLinkedList *list);
void sll_get_node_data(Node node, void (*print_data_function)(Data));
// void sll_free(Node head);
void sll_print(SinglyLinkedList list, void (*print_data_function)(Data));
Node sll_prepend(SinglyLinkedList *list, Data data);
Node sll_search(SinglyLinkedList list, Data searchData, int (*compare)(const Data a, const Data b));
void sll_delete(SinglyLinkedList *list, Node targetNode);