#include "../header/menu.h"
#include "checkout.c"

MenuItem menuItems[MAX_MENU_ITEMS] = {
    {"香辣鸡腿堡", 12.50},
    {"劲脆鸡腿堡", 12.50},
    {"新奥尔良烤鸡腿堡", 13.50},
    {"老北京/墨西哥鸡肉卷", 11.00},
    {"深海鳕鱼堡", 13.50},
    {"田园脆鸡堡", 8.00},
    {"川辣嫩牛五方", 14.00},
    {"薯条（小份）", 6.50},
    {"薯条（中份）", 7.50},
    {"薯条（大份）", 9.00},
    {"土豆泥", 3.50},
    {"香甜粟米棒", 5.00},
    {"上校鸡块（6块）", 11.00},
    {"奥尔良烤翅", 9.00},
    {"香辣鸡翅（对）", 8.00},
    {"芙蓉鲜蔬汤", 5.00},
    {"可乐（小杯）", 5.50},
    {"可乐（中杯）", 6.00},
    {"可乐（大杯）", 7.00},
    {"雪顶咖啡", 9.00},
    {"牛奶", 5.00},
    {"柠乐", 6.50},
    {"热巧克力", 5.00},
    {"圆筒冰激凌", 3.00}};

// 正在点餐
int isOrdering = 0;
OrderItem orderList[MAX_MENU_ITEMS];

void Menu()
{
  int choice;
  system("cls");

  showMenu();

  if (isOrdering)
  {
    showOrder();
  }

  printf("\n输入菜单序号点餐（输0结束点餐） >>");
  choice = getChoice();

  route(choice);

  system("cls");

  return;
}

void showMenu()
{
  printf("--------------肯德基菜单--------------\n\n");
  for (int i = 0; i < MAX_MENU_ITEMS; i++)
  {
    char index[4];
    snprintf(index, sizeof(index), "%d.", i + 1);
    printf("%-4s %-24s %6.2f元\n", index, menuItems[i].name, menuItems[i].price);
  }
  // printf("\n--------------------------------------\n");
}

void showOrder()
{
  printf("\n--------------------------------------\n");
  printf("点餐清单：\n");
  int orderIndex = 1;
  for (int i = 0; i < MAX_MENU_ITEMS; i++)
  {
    if (orderList[i].count > 0)
    {
      double itemTotal = menuItems[i].price * orderList[i].count;
      printf("%-4d %-12s %2.2f x %d = %2.2f元\n", orderIndex++, menuItems[i].name, menuItems[i].price, orderList[i].count, itemTotal);
    }
  }
  printf("--------------------------------------\n");
  printf("总价: %6.2f元\n", getTotalPrice(menuItems, orderList));
}

void addOrder(int id)
{
  orderList[id].count++;
}

int getChoice()
{
  int choice;
  while (scanf("%d", &choice) != 1)
  {
    while (getchar() != '\n')
      ;
    printf("输入有误，请重新输入 >>");
  }
  return choice;
}

void route(int choice)
{
  if (choice == 0)
  {
    checkout(getTotalPrice(menuItems, orderList));
    isOrdering = 0;
    for (int i = 0; i < MAX_MENU_ITEMS; i++)
    {
      orderList[i].count = 0;
    }
    return;
  }

  if (choice < 1 || choice > MAX_MENU_ITEMS)
  {
    printf("无效的选择，请重新输入。\n");
    return;
  }

  isOrdering = 1;
  addOrder(choice - 1);
  return;
}
