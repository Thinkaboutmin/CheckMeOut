#include <iostream>
#include <string>
#include "registerController.h"
#include "order.h"
#include "item.h"

registerController::registerController(StoreInventory * inventory, order * checkout)
{
  database = inventory;
  cart = checkout;
}

void registerController::processOrder()
{
  std::string command;
  double option;

  do
  {
    std::cout<<"> ";
    std::cin>>command>>option;
    
    if(command.compare("buy") == 0)
    {
      item add = database->lookup((int)option);
      cart->addItem(add);
    }
    else if(command.compare("pay") != 0)
    {
      std::cout<<"ACCEPTED COMMANDS:\n"
               <<"buy <item sku>\n"
               <<"pay <amount>\n";
    }
  }while( command.compare("pay") != 0 );
  cart->balance(option);
  screen.displayFinalReceipt(*cart);
}