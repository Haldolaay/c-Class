#include<iostream>
#include<string>
using namespace std;
int main(){
    int start,stop,step,numOfIt;

    while(true){
        cout<<"Enter start, stop, and step values (space separated): ";
        cin>>start>>stop>>step;
        numOfIt = (stop - start) / step + 1;
        if (stop<=start){
            cout<<"Oops! stop value must be greater than start value.";
            continue;
        }
        else if(step<=0){
            cout<<"Oops! step value must be greater than 0.";
            continue;
        }
        else if (numOfIt>50){
            cout<<"Oops! number of iterations should not exceed 50.";
            continue;
        }
        else{
            cout<<"Table written to number-table.txt";
            break;
        }


    }









}