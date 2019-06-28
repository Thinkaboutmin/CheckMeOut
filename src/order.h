#ifndef ORDER_H
#define ORDER_H
#include <vector>
#include "item.h"

class order {
  private:
    std::vector<item> itemList;
    double tax;
    bool closed;
  public:
    order();
    order(double);
  public:
    void addItem(item);
    std::vector <item> getItems();
    double getSubtotal();
    double getTax();
    double getTotal();
    double balance(double);
};

#endif
