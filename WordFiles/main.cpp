#include <iostream>
#include <fstream>
#include<string.h>
#include<vector>
#include<iomanip>
using namespace std;

void print(vector<string>name);//printing tests
void clean( string& name); //clear all punctuations and changes the letters to lowercase
void addName(string name, vector<string>&names);
//adding name to the master vector
void sorting(vector<string>&names);
//insertion sort
void run(ifstream & ifs, vector<string>&names);
//open an input stream
// clean the words and sort them
bool binary(string word, vector<string>arr);
void pushBack(vector<string>name, vector<string>&master);
//used to add words to final list
bool check(string word, vector<string>list);
//checks if duplicates exist
void noDuplicates(vector<string>&name);
//deletes duplicates
void write(vector<string>list,vector<string>alice
        ,vector<string>jeeves,vector<string>peter,vector<string>sherlock,vector<string>tom);
//writing result to a file


/*--------------------------------------------------*/
int main() {
    //file arrays:
    vector<string> bigName;
    vector<string> alice;
    vector<string> jeeves;
    vector<string> peterpan;
    vector<string> sherlock;
    vector<string>tomsawyer;
    vector<string> masterList;

    char option;//user option (q to stop)
    ifstream ifs; // input file
    int number = 0; // number of files processesd
    cout<<"please pick the file:"<<endl
        <<"a: alice.txt"<<endl
        <<"b: jeeves.txt"<<endl
        <<"c: peterpan.txt"<<endl
        <<"d: sherlock.txt"<<endl
        <<"e: tomsawyer.txt"<<endl
        <<"q: to stop      "<<endl;
    do{
        cin>>option;
        switch (option){
            case 'a':
                ifs.open("alice.txt");
                run(ifs,alice);
                pushBack(alice,masterList);
                number++;
                break;
            case 'b':
                ifs.open("jeeves.txt");
                run(ifs,jeeves);
                pushBack(jeeves,masterList);
                number++;
                break;
            case 'c':
                ifs.open("peterpan.txt");
                run(ifs,peterpan);
                pushBack(peterpan,masterList);
                number++;
                break;
            case 'd':
                ifs.open("sherlock.txt");
                run(ifs,sherlock);
                pushBack(sherlock,masterList);
                number++;
                break;
            case 'e':
                ifs.open("tomsawyer.txt");
                run(ifs,tomsawyer);
                pushBack(tomsawyer,masterList);
                number++;
                break;

        }
        ifs.close();
    }while(option !='q');

    write(masterList, alice,jeeves,peterpan,sherlock,
          tomsawyer);

    return 0;
}
/*----------------------------------------------------------------------*/
void print(vector<string>name,ofstream &ofs){//just used for printing
    for( int i=0; i<name.size(); i++){
        ofs<<name[i]<<endl;
    }
}
void clean( string& name){

    for (size_t i =0; i< name.length(); i++){
        // if (!((name[i] <= 'z' && name[i] >= 'a') || (name[i] <= 'Z' && name[i] >= 'A'))){
        if (!isalpha(name[i])){
            if (name[i] =='-'){
                name.replace(i+1,1," ");
            }
            name.replace(i,1,"");
            i--;
        }else{
            name[i]=tolower(name[i]);
        }
    }
}
void addName(string name, vector<string>&names){//adding name to the master vector
    if (name.length()==7){

        names.push_back(name);

    }
}
void sorting(vector<string>&names){//insertion sort
    string temp;
    for( int i =1; i<names.size(); i++){
        int j =i;
        while(j>0 && names[j]<names[j-1]){
            temp = names[j];
            names[j]= names[j-1];
            names[j-1]= temp;
            j--;
        }
    }


}
void run(ifstream & ifs, vector<string>&names){
    //open an input stream
    // clean the words and sort them
    string word;
    if (!ifs) {
        cout << "Failed to open file for read: " <<endl;
        return;
    }
    while( ifs>>word){
        clean(word);
        addName(word,names);
        sorting(names);
    }

}
bool binary(string word, vector<string>arr){

    int low =0;
    int high = arr.size()-1;
    int mid ;
    while( high >= low){
        mid = (low+high)/2;
        if(word > arr[mid]){
            low= mid+1;

        }
        else if(word < arr[mid]) {
            high = mid-1;

        }
        else if (word == arr[mid]){return true;}
    }
    return false;
}
void pushBack(vector<string>name, vector<string>&master){
    //used to add words to final list
    for( int i =0; i<name.size(); i++){
        master.push_back(name[i]);
    }

}
bool check(string word, vector<string>list){
    //checks if duplicates exist
    int counter =0;
    for (int i= 0; i<list.size(); i++){
        if (word == list[i]){counter++;}

    }
    return (counter>1?true:false);
}
void noDuplicates(vector<string>&name)
{//deletes duplicates
    for (int i= 0; i<name.size(); i++){
        if (check(name[i],name)){
            name.erase(name.begin()+i);
            i--;
        }

    }

}
void write(vector<string>list,vector<string>alice
        ,vector<string>jeeves,vector<string>peter,vector<string>sherlock,vector<string>tom){
    noDuplicates(list); //cleaning the list before use
    int count =0; // to check the word and appereances
    ofstream ofs("word-data.txt");
    vector<string>five;//five apperances
    vector<string>three;//three apperances
    // vector<string>one;// unique
    // vector<string>unique;

    int A=0,J=0,S=0,P=0,T=0;
    int Acount=0, Jcount=0, Scount=0, Pcount=0;
    int Tcount=0;
    if(!ofs)cout << "Error..";

    for (int i =0; i<list.size(); i++){
        A=0,J=0,S=0,P=0,T=0;
        sorting(list);
        ofs<<list[i];
        ofs<<" ";
        if(binary(list[i],alice)){ofs<<"A"; count++;A++;}else{ofs<<".";}
        if(binary(list[i],jeeves)){ofs<<"J"; count++;J++;}else{ofs<<".";}
        if(binary(list[i],peter)){ofs<<"P"; count++;P++;}else{ofs<<".";}
        if(binary(list[i],sherlock)){ofs<<"S"; count++;S++;}else{ofs<<".";}
        if(binary(list[i],tom)){ofs<<"T"; count++;T++;}else{ofs<<".";}
        ofs<<" "<<count<<endl;
        if(count ==5){
            five.push_back(list[i]);
        }
        if(count >=3 ){
            three.push_back(list[i]);
        }else if (count ==1){
            if (A> 0){Acount++;}
            else if (J>0){Jcount++;}
            else if (P>0){Pcount++;}
            else if (S>0){Scount++;}
            else if (T>0){Tcount++;}
        }
        count=0;
    }
    // i didn't know whether to display this part of the code in cout or in file, and i build my print() functions for files, so i used this quick change just incase
    // ofs<<endl;
    // ofs<<"=== Seven-Letter Word Analysis ===";
    // ofs<<endl<<endl;
    // ofs<<"Words appearing in all five passages:";
    // ofs<<endl<<endl;
    // print(five,ofs);
    // ofs<<endl<<endl;
    // ofs<<"Words appearing in at least three passages:";
    // ofs<<endl;
    // print(three,ofs);
    // ofs<<endl;
    // ofs<<"# Words unique to each passage:";
    // ofs<<endl<<endl;
    // ofs<<setw(14)<<"alice :"<< Acount<<endl;
    // ofs<<setw(14)<<"jeeves :"<< Jcount<<endl;
    // ofs<<setw(14)<< "peterpan :"<< Pcount<<endl;
    // ofs<< setw(14)<<"sherlock :"<< Scount<<endl;
    // ofs<<setw(14)<<"tomsawyer :"<< Tcount<<endl;


    ofs.close();

    ofs<<endl;
    cout<<"=== Seven-Letter Word Analysis ===";
    cout<<endl<<endl;
    cout<<"Words appearing in all five passages:";
    cout<<endl<<endl;
    for( int i=0; i<five.size(); i++){
        cout<<five[i]<<endl;
    }
    cout<<endl<<endl;
    cout<<"Words appearing in at least three passages:";
    cout<<endl;
    for( int i=0; i<three.size(); i++){
        cout<<three[i]<<endl;
    }
    cout<<endl;
    cout<<"# Words unique to each passage:";
    cout<<endl<<endl;
    cout<<setw(14)<<"alice :"<< Acount<<endl;
    cout<<setw(14)<<"jeeves :"<< Jcount<<endl;
    cout<<setw(14)<< "peterpan :"<< Pcount<<endl;
    cout<< setw(14)<<"sherlock :"<< Scount<<endl;
    cout<<setw(14)<<"tomsawyer :"<< Tcount<<endl;
}
