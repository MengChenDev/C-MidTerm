// menu.h
#include <stdio.h>
#include <stdlib.h>
#ifndef MENU_H
#define MENU_H
#define MAX_MENU_ITEMS 24

typedef struct
{
  char name[50];
  float price;
} MenuItem;

typedef struct
{
  int id;
  int count;
} OrderItem;

void Menu();
void showMenu();
void showOrder();
void addOrder(int id);
int getChoice();
void route(int choice);

#endif // MENU_H
