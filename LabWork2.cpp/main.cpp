#include<iostream>
#include<string>
using namespace std;
int main(){
    const int INFINIT = 1;// used for infinite loop,can be any number bigger than 0
    int no1,no2,count,count2;
    string fName,sName;
    count = 1;// will be used to count to 100
    count2 =count;// will be used for the 10 mark space
    cout<<"== Fizz Buzz Deluxe =="<<endl;
    while(INFINIT>0){//infinite loop
        cout<<"Enter a pair of words (each from 3-6 chars long): ";
        cin>>fName>>sName;
        // check the name length using .length()
        if((fName.length()<3||fName.length()>6)||(sName.length()<3)||(sName.length()>6)){
            continue;
        }else{
            cout<<endl;
            break;
        }
        cout<<endl;
    }
    while(INFINIT>0){//checking the number

        cout<<"Enter two different integers (between 2 and 15): ";
        cin>>no1>>no2;
        if(no1 == no2){continue;}
        else{
        if((no1<2 ||no1>15)||(no2<2||no2>15)){
            continue;
        }else{
            cout<<endl;
            break;
        }}
    }
    cout<<" ";
    while(count<=100){//printing the first portion
        if(count%no1==0 && count%no2==0){cout<<fName<<sName;}
        else if(count%no2==0){cout<<sName;}
        else if(count%no1==0){cout<<fName;}
        else {cout<<count;};
        count++;
        count2++;
        if(count2==11){
            cout<<endl;
            count2 = 1;
        }
        cout<<" ";

    }
    count = 1;
    cout<<endl;
    cout<<" ";
    while(count<=100){
        if(count%no1==0 && count%no2==0){cout<<"#";}
        else if(count%no2==0){cout<<"*";}
        else if(count%no1==0){cout<<"+";}
        else {cout<<".";};
        count++;
        count2++;
        if(count2==11 && count<98){
            cout<<endl;
            count2 = 1;
        }
        cout<<" ";

    }

cout<<endl;



}