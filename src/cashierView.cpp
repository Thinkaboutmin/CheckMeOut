#include <iostream>
#include <iomanip>
#include <vector>
#include "cashierView.h"

void cashierView::displayRunningTotal(order running)
{
  std::cout<<"================\n"
           <<"CASHIER'S SCREEN\n";
  std::vector <item> cart = running.getItems();
  std::cout<<std::setprecision(2)<<std::fixed;
  for(int i=0; i<cart.size(); i++)
  {
    std::cout<<cart[i].getName()<<" $"<<cart[i].getPrice()<<std::endl;
  }
  std::cout<<"SUBTOTAL: $"<<running.getSubtotal()<<std::endl
           <<"================\n";
}

void cashierView::displayFinalReceipt(order final)
{
  std::cout<<"================\n"
           <<"CASHIER'S SCREEN\n";
  std::vector <item> cart = final.getItems();
  std::cout<<std::setprecision(2)<<std::fixed;
  for(int i=0; i<cart.size(); i++)
  {
    std::cout<<cart[i].getName()<<" $"<<cart[i].getPrice()<<std::endl;
  }
  std::cout<<"SUBTOTAL: $"<<final.getSubtotal()<<std::endl
           <<"TAXES: $"<<final.getTax()<<std::endl
           <<"----------------\n"
           <<"TOTAL: $"<<final.getTotal()<<std::endl
           <<"================\n";
}