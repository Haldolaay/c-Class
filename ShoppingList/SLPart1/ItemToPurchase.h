//
// Created by w1739670 on 5/9/2019.
//
#include <string>
#ifndef CH13_ITEMTOPURCHASE_H
#define CH13_ITEMTOPURCHASE_H


class ItemToPurchase {
public:
ItemToPurchase();
ItemToPurchase(std::string name, double price, int quantity);
    void setName(std::string name);
    void setPrice(double price);
    void setQuantity(int quantity);
    std::string getName() const  {return this->itemName;};
    double getPrice() const {return this->itemPrice;};
    int getQuantity() const {return this-> itemQuantity;};
    void printItemCost();




private:
    std::string itemName;
    double itemPrice;
    int itemQuantity;
};


#endif //CH13_ITEMTOPURCHASE_H
