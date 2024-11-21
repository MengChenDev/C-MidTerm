#include "../header/checkout.h"

double getTotalPrice(MenuItem menuItems[], OrderItem orderList[])
{
  double totalPrice = 0.0;
  for (int i = 0; i < MAX_MENU_ITEMS; i++)
  {
    if (orderList[i].count > 0)
    {
      totalPrice += menuItems[i].price * orderList[i].count;
    }
  }
  return totalPrice;
}

void checkout(double totalPrice)
{
  double actualPayment;
  double change;
  printf("--------------------------------------\n");
  printf("应付款: %6.2f元\n", totalPrice);

  // 获取实付款
  do
  {
    printf("请输入实付款金额 >>");
    scanf("%lf", &actualPayment);
    if (actualPayment < MIN_PAYMENT)
    {
      printf("付款金额不能为负，请重新输入。\n");
    }
    else if (actualPayment > MAX_PAYMENT)
    {
      printf("付款金额超出最大限制，请重新输入。\n");
    }
    else if (actualPayment < totalPrice)
    {
      printf("付款不足，还需支付 %6.2f元。\n", totalPrice - actualPayment);
    }
  } while (actualPayment < totalPrice || actualPayment < MIN_PAYMENT || actualPayment > MAX_PAYMENT);

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