#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    string currPattern;
    bool loop = true;
    int patLen;
    string newPattern;
    int count1=0,count2=0,count3=0,count4=0,genCount=0;
    currPattern = "**$";
    int patLen2;

    while (loop){
        cout << "Enter maximum pattern length (10 - 60): ";
        cin >> patLen;
        if (patLen >= 10 && patLen <= 60){
            loop = false;
        }
    }
    cout<<endl;
    patLen2 = currPattern.length();
    cout << setw(4) << genCount << ": " << currPattern << endl;
    while (patLen2 < patLen) {
        for (int x = 0; currPattern[x] != '\0'; x++) {
            if (currPattern[x] == '*') {
                newPattern.insert(0, "$.");
                count3++;
                count2++;

            }
            if (currPattern[x] == '$') {
                newPattern.append(".*");
                count3++;
                count1++;

            }
            if (currPattern[x] == '.') {
                newPattern.insert(newPattern.length() / 2, "*-");
                count1++;
                count4++;
            }
            if (currPattern[x] == '-') {
                newPattern = newPattern.substr(1, newPattern.length() - 2);

            }
        }

        currPattern = newPattern;
        patLen2 = currPattern.length();
        newPattern = "";
        genCount++;
        cout << setw(4) << genCount << ": " << currPattern << endl;
    }
    cout << "\n";
    cout << "After " << genCount << " generations, pattern length is " << currPattern.length() << "\n" << endl;
    cout << "Total Symbols Generated:" << endl << "  $ x " << count2 << endl;
    cout << "  * x " << count1 << endl;
    cout << "  . x " << count3 << endl;
    cout <<  "  - x " << count4 << endl;
    return 0;
}