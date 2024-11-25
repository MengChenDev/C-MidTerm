// menu.h
#include <stdio.h>
#include <stdlib.h>
#ifndef MENU_H
#define MENU_H
#define MAX_MENU_ITEMS 24
#define MAX_NAME_LENGTH 50

int orderCounts[MAX_MENU_ITEMS];

void Menu();
void showMenu();
void showOrder();
int getCount();
void setOrder(int id, int count);
int getChoice();
void route(int choice);

#endif // MENU_H
