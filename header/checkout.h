#include "../header/menu.h"
#define MAX_PAYMENT 1000.0
#define MIN_PAYMENT 0.0

double getTotalPrice(MenuItem menuItems[], OrderItem orderList[]);
void checkout(double totalPrice);