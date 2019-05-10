//
// Created by w1739670 on 5/9/2019.
//
#include <iostream>
#include "ShoppingCart.h"
#include "ItemToPurchase.h"
using namespace std;
ShoppingCart::ShoppingCart() {

}

ShoppingCart::ShoppingCart(string name) {
        this->customerName = name;
}

string ShoppingCart::getCustomerName() const {
        return this-> customerName;
}

void ShoppingCart::addItem(ItemToPurchase value) {
        cartItems.push_back(value);
}

void ShoppingCart::removeItem(string name) {
        for (size_t i =0; i<cartItems.size(); i++){
                //if (cartItems.at[i].getName() == name ){ FIXME // doesn't work for some reason!
                if (cartItems[i].getName() == name ){
                        cartItems.erase(cartItems.begin() + i);
                        return;
                }

        }
        cout<< "Item not found in cart. Nothing removed."<<endl;
}

void ShoppingCart::changeQuantity(string name, int quantity) {
        for (size_t i =0; i< cartItems.size();i++){
                if (cartItems[i].getName()== name){
                        cartItems[i].setQuantity(quantity);
                }

        }
        cout<<"Item not found in cart. Nothing modified."<<endl;
}

double ShoppingCart::getTotalCost() {
        double runningSum = 0000000000000000;
        for (size_t i =0; i< cartItems.size();i++) {

                runningSum = runningSum+cartItems[i].getQuantity()*cartItems[i].getPrice();


        }
        return runningSum;
}

void ShoppingCart::printCart() {
        double total =0;
        cout<<this->getCustomerName()<<"'s Shopping Cart"<<endl;
        for (size_t i =0; i<cartItems.size();i++){
                total = total+ cartItems[i].getPrice()*cartItems[i].getQuantity();
                cartItems[i].printItemCost();
        }
        cout<<"Total: $"<< total;
};
