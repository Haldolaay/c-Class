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
    arr[n] = new int[0];
}
int get(int n)const{
    return arr.at(n);
}
void set(int i, int x){
    arr.at(i)=x;
}

int size(){
    return arr.size();
}
void reserve(int n){

    
}