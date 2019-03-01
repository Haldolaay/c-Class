#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
int start,stop,step,numOfIt;
fstream file;
file.open("./number-table.txt");
    if (!file.is_open()) {return 1;}
while(true){
cout<<"Enter start, stop, and step values (space separated): ";
cin>>start>>stop>>step;

if (stop<=start){
cout<<"Oops! stop value must be greater than start value."<<endl;
continue;
}
 if(step<=0){
  cout<<"Oops! step value must be greater than 0."<<endl;
  continue;
}
numOfIt = (stop - start) / step + 1;
 if (numOfIt>50){
  cout<<"Oops! number of iterations should not exceed 50."<<endl;
  continue;
}

  cout<<"Table written to number-table.txt"<<endl;
  break;



}

return 0;







}