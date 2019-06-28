#ifndef _KEYPADCONTROLLER_H_
#define _KEYPADCONTROLLER_H_
#include "order.h"
#include "customerView.h"

class keypadController
{
private:
  order *cart;
  customerView display;
public:
  keypadController(order *);
};

#endif