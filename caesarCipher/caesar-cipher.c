// -----------------------------------------------------------------------
// caesar-cipher.c
// -----------------------------------------------------------------------
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// -----------------------------------------------------------------------
// Function prototypes

// Returns true (1) if `str` ends in ".txt", else false (0)
int validFileSuffix(char str[]);

// Returns the given character shifted by the given amount
int shiftChar(int ch, int shift);

// Shifts all alphabetic characters by the given amount
void shiftStr(char str[], int shift);

// Reads in a file, enciphers with the given key, and writes the result
void encipher(FILE *inFile, FILE *outFile, int key);

// -----------------------------------------------------------------------
// Global constants

const int BUFFER_SIZE = 2048;

// -----------------------------------------------------------------------
// Main program

int main() {
    char inName[BUFFER_SIZE];
    char outName[BUFFER_SIZE];
    char outPrefix[BUFFER_SIZE];

    // TODO (0): declare strings (character arrays) for outName and outPrefix

    int key;

    // TODO (1): Prompt for, and read in, input file name
    printf("Enter input file name (*.txt): \n");
    // TODO (2): Validate file name
    scanf("%s",inName);
    // while ( ...not valid... ) {
    // Error message
    // Prompt for, and read in, input file name
    // }
    while(!validFileSuffix(inName)){
        printf("Error:  *.txt required.\n");
        printf("Enter input file name (*.txt): \n");
        scanf("%s",inName);
    }
    // TODO (3): Open input file for read (exit program if error)
    FILE* inFile = NULL;
    inFile =fopen(inName, "r");
    if (inFile == NULL) {
        printf("Could not open file myfile.txt.\n");
        return -1;
    }
    // TODO (4): Prompt for, and read in, output file prefix
    printf("Enter output file prefix: ");
    scanf("%s",outPrefix);
    // TODO (5a): Copy prefix to output file name string
    FILE* outFile =NULL;
    strcat(outPrefix,inName);
    // TODO (5b): Concatenate input file name to output file name string

    // TODO (6): Open output file for write (exit program, if error)
    outFile = fopen(outPrefix,"w");
    if (outFile == NULL) {
        printf("Could not open file myoutfile.txt.\n");
        return -1;
    }
    // TODO (7): Prompt and read key (don't forget the & for the int on scanf)
    printf("Enter key (integer): ");
    scanf("%d",&key);
    printf("Encrypting...\n");
    encipher(inFile, outFile, key);
    printf("Done.\n");

    // TODO (8): Close the input and output files
    fclose(inFile);
    fclose(outFile);
    return 0;
}

// -----------------------------------------------------------------------
// Function implementations

// TODO (9): validFileSuffix
// Returns true (1) if `str` ends in ".txt", else false (0)
int validFileSuffix(char str[]){
    if (strlen(str)>4){
        if (strchr(str, '.') != NULL){
            if(strchr(str,'t')!= NULL){
                if(strchr(str,'x')!=NULL){
                    return 1;
                }
            }

        }
    }
    return 0;
}
// TODO (10): shiftChar
// Returns the given character shifted by the given amount
// only change the character if `isalpha(ch)` is true
// if ch is uppercase
// if ch + shift < 'A', add 26 to the result
// if ch + shift > 'Z', subtract 26 from the result
// if ch is lowercase
// same deal as above, but with 'a' and 'z'
int shiftChar(int ch, int shift){
    if (isalpha(ch)){
        int key = ch +shift;
        if(islower(ch)){

            if(key < 'a'){return key+26;}
            else if (key > 'z'){return key-26;}
            else{return key;}

        }else{
            if(key < 'A'){return key+26;}
            else if (key > 'Z'){return key-26;}
            else{return key;}

        }

    }
    return ch;
}
// TODO (11): shiftStr
// Shifts all alphabetic characters by the given amount
// Mod the shift with 26 (to ensure it is in the range 0..25)
// Iterate over every character in the string:
// replace character with shifted character (call shiftChar(...))
void shiftStr(char str[], int shift){
    for (int i =0; i<strlen(str); i++){
        str[i] = shiftChar(str[i],shift);
    }
}
// TODO (12): encipher
// Reads in a file, enciphers with the given key, and writes the result
// Declare a string of size BUFFER_SIZE
// Using fgets(...), read while it does not return NULL
// Call shiftStr(...) to shift the buffer
// Use fprintf(...) to output the shifted string to the output file
//void encipher(FILE *inFile, FILE *outFile, int key){
//    char read[BUFFER_SIZE];
//    while(!feof(inFile)){
//        fgets(read,BUFFER_SIZE,inFile);
//
//        shiftStr(read,key);
//
//            fprintf(outFile, "%s", read);
//
//    }
//
//}
void encipher(FILE *inFile, FILE *outFile, int key){
    char read[BUFFER_SIZE];
    while(fgets(read,BUFFER_SIZE,inFile)){


        shiftStr(read,key);

            fprintf(outFile, "%s", read);

    }

}