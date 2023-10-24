#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "singly_linked_list.h"

struct PhoneData
{
  char model[30];
  int price;
};

typedef struct PhoneData Elementtype;

void print_data_function(Data data)
{
  Elementtype *element = (Elementtype *)data;
  printf("Model: %s, Price: %d\n", element->model, element->price);
}

int main()
{
  Elementtype phone1;
  strcpy(phone1.model, "iPhone 13 Pro");
  phone1.price = 1099;

  Elementtype phone2;
  strcpy(phone2.model, "Samsung Galaxy S21");
  phone2.price = 899;

  Node head = NULL;
menu:
{
  printf("   MENU\n");
  printf(" 1. Prepend\n");
  printf(" 2. Quit\n");
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
    sll_prepend(&head, &phone1);
    printf("____________________________________________\n");
    goto menu;
    ;
  }
  case 2:
  {
    printf("\n");
    sll_print(head, print_data_function);
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