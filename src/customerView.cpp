#include <iostream>
#include <iomanip>
#include "customerView.h"

void customerView::refresh(order running)
{
  std::cout<<"===============\n"
           <<"CUSTOMER SCREEN\n"
           <<"$"<<std::setprecision(2)<<std::fixed
           <<running.getSubtotal()<<std::endl
           <<"===============\n";
}