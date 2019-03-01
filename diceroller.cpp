#include <iostream>
#include <random>
#include <stdlib.h>
using namespace std;

int main() {
    srand(32767);

    cout << "Enter dice throw designators..." << endl
         << " # dice: 1 to 8, # sides: 4, 6, 8, 10, 12" << endl
         << " e.g. '2d6', or '0' to quit" << endl;

    int nDice, nSides, sum;
    char d;
    int count;

    // A "forever" loop...
    while (true) {
        sum = 0;
        cout << "> ";
        cin >> nDice;
        if (nDice == 0) {
            // User signal to end the prgram
            break;
        }
        cin >> d >> nSides;
        cout << endl;
        if((nDice > 0 && nDice<9)&&(d =='d')&&(nSides ==4 ||nSides ==6 ||nSides ==8 ||nSides ==10 ||nSides==12)){

            cout<<nDice<<d<<nSides<<" result: ";
            for(int i =1; i<=nDice;i++){
                count =rand() % nSides+1;
                sum+=count;
                cout<<count;
                if(i != nDice){cout<<" + ";}
            }
            cout<<" = "<<sum<<endl;

        }else {cout<<"Invalid Designator"<<endl;}
    }

    return 0;
}
