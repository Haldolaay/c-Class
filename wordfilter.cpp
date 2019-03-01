#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    string fileName, fileName2, fileName3;
    ifstream fileMain;
    ofstream fileMain2, fileMain3;
    string word;
    int count1 = 0, count2 = 0;

    bool loop = true;
    while (loop){
        cout << "Enter the name of the input file: " << endl;
        cin >> fileName;
        if (fileName.find(".txt") == string::npos)
        {
            cout << "Only filenames ending in '.txt' are accepted!" << endl;
        }
        else
        {
            loop = false;
        }
    }
    fileMain.open(fileName.c_str());
    if (!fileMain.is_open()) {
        cout << "Failed to open file for read: " << fileName << endl;
        return 1;
    }
    fileName2 = fileName.substr(0,fileName.find(".txt")) + "-odd.txt";
    fileMain2.open(fileName2.c_str());

    fileName3 = fileName.substr(0,fileName.find(".txt")) + "-even.txt";
    fileMain3.open(fileName3.c_str());

    while(!fileMain.eof()) {
        fileMain >> word;
        if (!fileMain.eof()) {
            if (word.length() % 2 == 0) {
                fileMain3 << word << endl;
                count1++;
            }
            if (word.length() % 2 == 1) {
                fileMain2 << word << endl;
                count2++;
            }
        }
    }
    cout << count1 + count2 << " words read in from " << fileName << endl;
    cout << count1 << " words written to " << fileName3 << endl;
    cout << count2 << " words written to " << fileName2 << endl;

    fileMain.close();
    fileMain2.close();
    fileMain3.close();
    return 0;
}