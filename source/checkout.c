
#include "../header/checkout.h"
#include <stdio.h>

double getTotalPrice(double menuPrices[], int orderCounts[])
{
  double totalPrice = 0.0;
  for (int i = 0; i < MAX_MENU_ITEMS; i++)
  {
    if (orderCounts[i] > 0)
    {
      totalPrice += menuPrices[i] * orderCounts[i];
    }
  }
  return totalPrice;
}

void checkout(double totalPrice)
{
  double actualPayment;
  double change;
  int result;
  printf("--------------------------------------\n");
  printf("应付款: %6.2f元\n", totalPrice);

  // 获取实付款
  do
  {
    printf("请输入实付款金额 >>");
    result = scanf("%lf", &actualPayment);
    if (result == 0)
    {
      printf("输入无效，请输入一个数字。\n");
      while (getchar() != '\n'); // 清空输入缓冲区
      continue;
    }
    if (actualPayment < MIN_PAYMENT)
    {
      printf("付款金额不能为负，请重新输入。\n");
    }
    else if (actualPayment < totalPrice)
    {
      printf("付款不足，还需支付 %6.2f元。\n", totalPrice - actualPayment);
    }
  } while (result == 0 || actualPayment < totalPrice || actualPayment < MIN_PAYMENT);

  // 计算找零
  change = actualPayment - totalPrice;

  // 显示找零
  printf("--------------------------------------\n");
  printf("实付款: %6.2f元\n", actualPayment);
  printf("找零: %6.2f元\n", change);
  printf("--------------------------------------\n");
  printf("结账完毕，按下回车为下一位客户点餐\n");
  getchar();
  getchar();
}