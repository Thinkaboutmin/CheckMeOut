#ifndef ITEM_H
#define ITEM_H
#include <string>
#include "IItem.h"


class item : public IItem {
  private:
    std::string name;
    double price;
    int sku;
  public:
    item();
    item(std::string, double, int);
  public:
    std::string getName();
    double getPrice();
    int getSKU();
};

#endif