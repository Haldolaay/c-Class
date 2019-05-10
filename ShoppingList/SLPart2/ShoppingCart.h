
#include <string>
#include <vector>
#include "ItemToPurchase.h"
#ifndef CH13_SHOPPINGCART_H
#define CH13_SHOPPINGCART_H


class ShoppingCart {
public:
    ShoppingCart();
    ShoppingCart(std::string name);
    std::string getCustomerName() const;
    void addItem(ItemToPurchase value);
    void removeItem(std::string name);
    void changeQuantity(std::string name, int quantity);
    double getTotalCost();
    void printCart();

private:
     std::string customerName;
    std::vector<ItemToPurchase> cartItems;
};


#endif //CH13_SHOPPINGCART_H
