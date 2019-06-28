#ifndef _CASHIERVIEW_H_
#define _CASHIERVIEW_H_
#include "order.h"

class cashierView
{
  public:
    void displayRunningTotal(order running);

    void displayFinalReceipt(order final);
};

#endif