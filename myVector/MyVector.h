//
// Created by hamza on 5/14/2019.
//

#ifndef MYVECTOR_MYVECTOR_H
#define MYVECTOR_MYVECTOR_H


class MyVector {
public:
    MyVector();
    MyVector(int n);

    int get(int n)const ;

    void set(int i, int x);

    int size();

    int capacity();

    void reserve(int n);

    void push_back(int x);

private:
    int sz;
    int space;
    int *arr;
};


#endif //MYVECTOR_MYVECTOR_H
