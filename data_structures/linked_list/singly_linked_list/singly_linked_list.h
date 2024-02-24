/**
 * @file singly_linked_list.h
 * @brief Singly Linked List Implementation
 * 
 * This file provides the implementation of a singly linked list in C.
 * 
 * @author tomodachii
 */

#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

/**
 * @brief Defines a type alias for void* with a different name.
 * 
 * This typedef allows for a more descriptive name to be used for pointers
 * that can point to any data type.
 */
typedef void *Data;

/**
 * @brief Defines the structure for a node in a singly linked list.
 * 
 * Each node in the singly linked list contains a pointer to data of type
 * Data and a pointer to the next node in the list.
 */
typedef struct SinglyLinkedListNode
{
  Data data; /**< Pointer to the data stored in the node */
  struct SinglyLinkedListNode *next; /**< Pointer to the next node in the list */
} SinglyLinkedListNode;

/**
 * @brief Defines a type alias for a pointer to a SinglyLinkedListNode structure.
 * 
 * This typedef allows for a more convenient way to refer to pointers to nodes
 * in the singly linked list.
 */
typedef SinglyLinkedListNode *Node;

/**
 * @brief Defines the structure for a singly linked list.
 * 
 * The singly linked list structure contains a pointer to the head node of the list.
 */
typedef struct SinglyLinkedList
{
  Node head; /**< Pointer to the head node of the list */
} SinglyLinkedList;

/**
 * Creates a new node for a singly linked list.
 * 
 * This function allocates memory for a new node in the singly linked list
 * and initializes its data and next pointer.
 * 
 * @param data The data to be stored in the new node.
 * @return A pointer to the newly created node if successful, or NULL if memory allocation fails.
 */
Node _sll_make_new_node(Data data);

/**
 * Initializes a singly linked list by setting its head pointer to NULL,
 * indicating an empty list.
 * 
 * @param list A SinglyLinkedList pointer.
 *             The head pointer of the list will be set to NULL.
 * 
 * @note
 * If we pass `SinglyLinkedList list` instead of the `SinglyLinkedList` pointer `*list` then
 * the statement `the list.head = NULL;` will not set the head of the list to NULL 
 * since it is passed by value!
 * 
 * @return The newly created node.
 */
void sll_init(SinglyLinkedList *list);

/**
 * Prints the data of a node in a singly linked list.
 * 
 * This function prints the data stored in the given node of a singly linked list
 * using the user provided print_data_function callback.
 * 
 * @param node The node whose data will be printed.
 * @param print_data_function A function pointer to a user-defined function that
 *                            prints the data stored in each node.
 */
void sll_get_node_data(Node node, void (*print_data_function)(Data));

// void sll_free(Node head);

/**
 * Traverses the given singly linked list and prints the data
 * stored in each node using the provided `print_data_function` callback.
 * 
 * @param list The singly linked list to be printed.
 * @param print_data_function A function pointer to a user-defined function that
 *                            prints the data stored in each node.
 */
void sll_print(SinglyLinkedList list, void (*print_data_function)(Data));

/**
 * Creates a new node and adds it to the beginning of the given singly linked list.
 * 
 * @param list A pointer to the SinglyLinkedList structure representing the list.
 * @param data The data to be stored in the new node.
 * @return The newly prepended node, which is now the head of the list.
 */
Node sll_prepend(SinglyLinkedList *list, Data data);

/**
 * Searches for a node containing the specified data in a singly linked list.
 * 
 * Traverses the given singly linked list and searches for a node
 * containing the specified data. It uses the provided compare function to determine
 * whether the data in each node matches the search data.
 * 
 * @param list The singly linked list to be searched.
 * @param searchData The data to search for.
 * @param compare A function pointer to a user-defined comparison function.
 * @return A pointer to the node containing the search data if found, or NULL otherwise.
 *
 * @note
 * The compare function should have the following signature:
 *   ```int compare(const Data a, const Data b);```
 * It should return 1 if the two data values are considered equal, and 0 otherwise.
 */
Node sll_search(SinglyLinkedList list, Data searchData, int (*compare)(const Data a, const Data b));

/**
 * Deletes the specified target node from the given singly linked list.
 * It updates the list structure accordingly by removing the target node and adjusting
 * the pointers of neighboring nodes.
 * 
 * @param list A pointer to the SinglyLinkedList structure representing the list.
 * @param targetNode The node to be deleted from the list.
 */
void sll_delete(SinglyLinkedList *list, Node targetNode);

#endif /* SINGLY_LINKED_LIST_H */