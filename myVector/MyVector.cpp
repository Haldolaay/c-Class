//
// Created by hamza on 5/14/2019.
//

#include "MyVector.h"
using namespace std;
MyVector::MyVector() {
    sz = 0;
    space =0;
    arr= nullptr;
}
MyVector::MyVector(int n) {
    sz= n;
    space =n;
    arr = new int[n];
    for (int i =0;i<sz;i++) {
        arr[i]= 0;
    }
}
int MyVector::get(int n)const{
    return arr[n];
}
void MyVector::set(int i, int x){
    arr[i]=x;
}

int MyVector::size(){
    return sz;
}
void MyVector::reserve(int n){
 int *temp = new int[n];
 for (int i =0; i<sz; i++){
     temp[i]=arr[i];
 }
 delete arr;
 arr = temp;
}
void MyVector::push_back(int x) {
    if (sz ==0) {
        space=1;
        reserve(space);
    }
    else if (sz == space) {
        space = space * 2;
        reserve(space);
    }

    arr[sz] = x;
    sz++;
}
int MyVector::capacity(){
    return space;
}


