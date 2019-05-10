#include <iostream>
#include "ItemToPurchase.h"
#include <iomanip>
using namespace std;
int main() {
    ItemToPurchase first;
    ItemToPurchase second;
    string name;
    double price;
    int quantity;
    cout << fixed << setprecision(2);

// first item info
    cout<< "Enter the item name:"<<endl;
    getline(cin, name );
    first.setName(name);

    cout<<"Enter the item price:"<<endl;
    cin>> price;
    first.setPrice(price);
    cout<<"Enter the item quantity:"<<endl;
    cin>>quantity;
    first.setQuantity(quantity);
    cin.ignore();
// second item info

    cout<< "Enter the item name:"<<endl;
    getline(cin, name );
    second.setName(name);
    //cin.ignore();
    cout<<"Enter the item price:"<<endl;
    cin>> price;
    second.setPrice(price);
    cout<<"Enter the item quantity:"<<endl;
    cin>>quantity;
    second.setQuantity(quantity);

// printing
first.printItemCost();
second.printItemCost();
cout<<"Total: $"<< (first.getPrice()*first.getQuantity())+(second.getPrice()*second.getQuantity());

    return 0;
}