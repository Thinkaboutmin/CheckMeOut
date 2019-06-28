#include "StoreInventory.h"
#include <fstream>

StoreInventory::~StoreInventory()
{
  inventory.clear();
}

StoreInventory::StoreInventory(const char filename[])
{
  std::ifstream db (filename);

  if( db.is_open() )
  {
    while( !db.eof() )
    {
      std::string produce;
      double price;
      int productID;
      db >> produce >> price >> productID;
      item newProduce(produce,price,productID);
      inventory.push_back(newProduce);
    }
  }
}

item StoreInventory::lookup(int sku)
{
  for(int i=0; i<inventory.size(); i++)
  {
    if( sku == inventory[i].getSKU() )
    {
      return inventory[i];
    }
  }
  item blank;
  return blank;
}