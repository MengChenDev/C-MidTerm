#include "../header/menu.h"
#include "checkout.c"

char menuItems[MAX_MENU_ITEMS][MAX_NAME_LENGTH + 1] = {
    "香辣鸡腿堡",
    "劲脆鸡腿堡",
    "新奥尔良烤鸡腿堡",
    "老北京/墨西哥鸡肉卷",
    "深海鳕鱼堡",
    "田园脆鸡堡",
    "川辣嫩牛五方",
    "薯条（小份）",
    "薯条（中份）",
    "薯条（大份）",
    "土豆泥",
    "香甜粟米棒",
    "上校鸡块（6块）",
    "奥尔良烤翅",
    "香辣鸡翅（对）",
    "芙蓉鲜蔬汤",
    "可乐（小杯）",
    "可乐（中杯）",
    "可乐（大杯）",
    "雪顶咖啡",
    "牛奶",
    "柠乐",
    "热巧克力",
    "圆筒冰激凌"};

double menuPrices[MAX_MENU_ITEMS] = {
    12.50,
    12.50,
    13.50,
    11.00,
    13.50,
    8.00,
    14.00,
    6.50,
    7.50,
    9.00,
    3.50,
    5.00,
    11.00,
    9.00,
    8.00,
    5.00,
    5.50,
    6.00,
    7.00,
    9.00,
    5.00,
    6.50,
    5.00,
    3.00};

// 正在点餐
int isOrdering = 0;

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
    printf("%-4s %-24s %6.2f元\n", index, menuItems[i], menuPrices[i]);
  }
}

void showOrder()
{
  printf("\n--------------------------------------\n");
  printf("点餐清单：\n");
  int orderIndex = 1;
  for (int i = 0; i < MAX_MENU_ITEMS; i++)
  {
    if (orderCounts[i] > 0)
    {
      double itemTotal = menuPrices[i] * orderCounts[i];
      printf("%-4d %-24s %2.2f x %d = %2.2f元\n", orderIndex++, menuItems[i], menuPrices[i], orderCounts[i], itemTotal);
    }
  }
  printf("--------------------------------------\n");
  printf("总价: %6.2f元\n", getTotalPrice(&menuPrices, &orderCounts));
}

int getCount()
{
  int count;
  printf("请输入数量 >>");
  while (scanf("%d", &count) != 1 || count < 0)
  {
    while (getchar() != '\n')
      ;
    printf("数量输入有误，请重新输入数量 >>");
  }
  return count;
}

void setOrder(int id, int count)
{
  orderCounts[id] = count;
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
  int count;
  if (choice == 0)
  {
    checkout(getTotalPrice(&menuPrices, &orderCounts));
    isOrdering = 0;
    for (int i = 0; i < MAX_MENU_ITEMS; i++)
    {
      orderCounts[i] = 0;
    }
    return;
  }

  if (choice < 1 || choice > MAX_MENU_ITEMS)
  {
    printf("无效的选择，请重新输入。\n");
    return;
  }

  count = getCount();
  isOrdering = 1;
  setOrder(choice - 1, count);
  return;
}
