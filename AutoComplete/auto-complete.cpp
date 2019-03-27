// -----------------------------------------------------------------------
// auto-complete.cpp
// -----------------------------------------------------------------------
#include <iostream>
#include <fstream>
using namespace std;

// -----------------------------------------------------------------------
// Global constants
const int MAX_SIZE = 4000000;
const string ORIGINAL_FILE_NAME = "ten-k-words.txt";
const string WORKING_FILE_NAME = "word-list.txt";

// global array for our word list
string words[MAX_SIZE];

// -----------------------------------------------------------------------
// Function prototypes

void insertionSort(string a[], int size);
int binarySearch(string a[], int size, string key);
int readDictionary(string a[], string fileName);
void writeDictionary(string a[], int size, string fileName);
int updateDictionary(string a[], int size, string s, string fileName);
void outputMatches(string a[], int size, string s);

// -----------------------------------------------------------------------
// Main Program

int main() {
    // read in words from our original word list (which we will not modify)
    int size = readDictionary(words, ORIGINAL_FILE_NAME);
    string input;

    // write words out to our working file
    writeDictionary(words, size, WORKING_FILE_NAME);

    // prompt the user for input; keep going till "q"
    cout << "Type one word.  \"q\" to quit." << endl;
    cout << "> ";
    cin >> input;
    while (input != "q") {
        outputMatches(words, size, input);
        size = updateDictionary(words, size, input, WORKING_FILE_NAME);
        cout << "> ";
        cin >> input;
    }
    return 0;
}


// -----------------------------------------------------------------------
// Function implementations


// TODO (1):  implement binarySearch
int binarySearch(string a[], int size, string key){
    int low = 0;
    int high = size - 1;
    int mid;
    while ( high >= low ){
        mid = ( high + low) / 2;
        if (key > a[mid]){low = mid + 1;}
        else if (key < a[mid]){high = mid - 1;}
        else if (key == a[mid]){return mid;}
    }
    return -1;
}

// TODO (2):  implement insertionSort
void insertionSort(string a[], int size){
    int i, j;
    string temp;
    for (i = 0; i < size; i++){
        j = i;
        while ( j > 0 && a[j] < a[j-1]){
            temp = a[j];
            a[j] = a[j-1];
            a[j-1] = temp;
            j--;
        }
    }

}

// TODO (3):  implement readDictionary
/*
 - Open an ifstream using fileName.
 - Verify that the file opened (if not, return -1).
 - Read one word at a time and store in `a`.
 - Close the input stream.
 - Return the number of words read.
*/
int readDictionary(string a[], string fileName){
    int i=0;
    ifstream ifs(fileName);
    if (!ifs){return -1;}
    while(ifs>>a[i]){
        i++;
    }
    ifs.close();
    return i;
}

// TODO (4):  implement writeDictionary
/*
 - Open an ofstream using fileName:
    - Use the default behavior of deleting the existing file,
      we will write a new one.
    - Be sure to check that the open was successful.
 - Write each element of `a` to the file.
 - Close the output stream.
*/
void writeDictionary(string a[], int size, string fileName){
    ofstream ofs(fileName);
    if (!ofs){cout<<"error reading file";}
    for(int i =0; i<size; i++){
        ofs<<a[i]<<"\n";
    }
    ofs.close();
}

// TODO (5):  implement updateDictionary
/*
 - Use `binarySearch` to search `a` for `s`
 - If `s` is NOT found at a valid index:
    - Assign `s` to the end of the array
        - The index of the end of the array is `size`
        - e.g. if `size` is 5, the new element should be written to index 5
    - Increment `size`
    - Sort `a` using `insertionSort`
    - Write `a` to the file using `writeDictionary`
 - Return the (possibly incremented) size
*/
int updateDictionary(string a[], int size, string s, string fileName){

    if (binarySearch(a,size,s)<0){
        a[size]=s;
        size++;
        insertionSort(a,size);
        writeDictionary(a,size,WORKING_FILE_NAME);
    }
    return size;

}

// TODO (6):  implement outputMatches
/*
 - loop through each element of `a`
    - Call `.find()` on each element, searching for `s`
    - If the element begins with `s`, (i.e. `.find()` returned 0),
      then print the element
*/
void outputMatches(string a[], int size, string s){
    int first;
    for (int i =0; i<size; i++){
        first = a[i].find(s);
        if(first ==0){
            cout<<a[i]<<endl;
        }

    }

}