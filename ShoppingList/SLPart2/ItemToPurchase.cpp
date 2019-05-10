//
// Created by w1739670 on 5/9/2019.
//
#include <iostream>
#include "ItemToPurchase.h"
using namespace std;
ItemToPurchase::ItemToPurchase() {
    this->itemName = "none";
    this->itemPrice = 0;
    this->itemQuantity = 0;

}

ItemToPurchase::ItemToPurchase(string name, double price, int quantity) {
    this->itemName = name;
    this->itemPrice = price;
    this->itemQuantity = quantity;
}

void ItemToPurchase::setName(string name) {
 this->itemName = name;
}

void ItemToPurchase::setPrice(double price) {
 this->itemPrice = price;
}

void ItemToPurchase::setQuantity(int quantity) {
   this->itemQuantity = quantity;

}
//printItemCost(), print itemName itemQuantity @ $itemPrice = $itemPrice * itemQuantity
void ItemToPurchase::printItemCost() {
cout<< this->itemName<< " "<< this->itemQuantity << " @ $"<< this->itemPrice<< " = $"<<(this->itemPrice * this->itemQuantity)<<endl;
}
