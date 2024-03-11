#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "singly_linked_list.h"

struct PhoneData
{
  char model[30];
  int price;
};

typedef struct PhoneData ElementType;

void print_phone_data_function(Data data)
{
  ElementType *element = (ElementType *)data;
  printf("Model: %s, Price: %d\n", element->model, element->price);
}

int search_phone_by_model(const Data a, const Data b)
{
  const ElementType *element = (const ElementType *)a;
  const char *strB = (const char *)b;

  return (strcmp(element->model, strB) == 0);
}

int main()
{
  ElementType phone1;
  strcpy(phone1.model, "iPhone 13 Pro");
  phone1.price = 1099;

  ElementType phone2;
  strcpy(phone2.model, "Samsung Galaxy S21");
  phone2.price = 899;

  SinglyLinkedList my_list;
  sll_init(&my_list);
menu:
{
  printf("   MENU\n");
  printf(" 1. Prepend\n");
  printf(" 2. Print\n");
  printf(" 3. Search\n");
  printf(" 4. Delete\n");
  printf("Any other keys: Quit Program\n");
  int c;
  printf("Your selection : ");
  scanf("%d", &c);
  while (getchar() != '\n')
    ;
  switch (c)
  {
  case 1:
  {
    printf("\n");
    sll_prepend(&my_list, &phone1);
    printf("____________________________________________\n");
    goto menu;
    ;
  }
  case 2:
  {
    printf("\n");
    sll_print(my_list, print_phone_data_function);
    printf("____________________________________________\n");
    goto menu;
    ;
  }
  case 3:
  {
    printf("\n");
    Node temp = NULL;
    temp = sll_search(my_list, "iPhone 13 Pro", search_phone_by_model);
    sll_get_node_data(temp, print_phone_data_function);
    printf("____________________________________________\n");
    goto menu;
    ;
  }
  case 4:
  {
    printf("\n");
    Node temp = NULL;
    temp = sll_search(my_list, "iPhone 13 Pro", search_phone_by_model);
    sll_get_node_data(temp, print_phone_data_function);
    sll_delete(&my_list, temp);
    printf("____________________________________________\n");
    goto menu;
    ;
  }
  default:
  {
    printf("Bye bye\n");
    return 0;
  }
  }
}
}