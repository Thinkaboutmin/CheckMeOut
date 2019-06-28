#ifndef _STORE_INVENTORY_H_
#define _STORE_INVENTORY_H_
#include <vector>
#include "item.h"

class StoreInventory
{
  private:
    std::vector<item> inventory;
  public:
    ~StoreInventory();
    StoreInventory(const char []);
    item lookup(int);
};

#endif