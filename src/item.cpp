#include "item.h"

item::item() {
  name = "Undefined Item";
  price = 0.00;
  sku = -1;
}

item::item(std::string name, double price, int sku) {
  this->name = name;
  this->price = price;
  this->sku = sku;
}

std::string item::getName() {
  return name;
}

double item::getPrice() {
  return price;
}

int item::getSKU() {
  return sku;
}