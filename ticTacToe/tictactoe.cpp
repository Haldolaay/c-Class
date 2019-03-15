// -----------------------------------------------------------------------
// tictactoe.cpp
// -----------------------------------------------------------------------
#include <iostream>
using namespace std;

// -----------------------------------------------------------------------
// Global constants

const int ROWS = 3;
const int COLS = 3;

const char EMPTY = '.';
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';

// -----------------------------------------------------------------------
// Function prototypes

void initBoard(char board[][COLS]);
void showBoard(char board[][COLS]);
void makeMove(char board[][COLS], char player);
bool gameOver(char board[][COLS]);

// -----------------------------------------------------------------------
// Main Program

int main() {
    char board[ROWS][COLS];
    char currentPlayer = PLAYER_X;

    initBoard(board);
    showBoard(board);


    while (!gameOver(board)) {
        makeMove(board, currentPlayer);
        showBoard(board);
        currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    return 0;
}

// -----------------------------------------------------------------------
// Game Implementation
void initBoard(char board[][COLS]){
    for (int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            board[i][j] = EMPTY;
        }
    }
}


void showBoard(char board[][COLS]){

    cout << "   1 2 3" << endl ;
    for (int i = 0; i < 3; i++){
        switch(i){
            case 0 : cout << "a  " ; break;
            case 1 : cout << "b  " ; break;
            case 2 : cout << "c  " ; break;
        }
        for(int j = 0 ; j < 3; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void makeMove(char board[][COLS], char player){
    char row,col;
    int r,c;
    while(1){
        cout << "Player " << player << "  enter your move: ";
        cin >> row >> col;

//if ( ( row =='a' || row =='b' || row =='c' )&& ( col >= 1 && col <= 3) )
//
        if (  row =='a' || row =='b' || row =='c' ){
            switch(row){
                case 'a' : r = 0 ; break;
                case 'b':  r = 1 ; break;
                case 'c':  r = 2 ; break;
            }
            if ( col == '1' || col == '2' || col == '3') {
                switch(col){
                    case '1': c = 0 ; break;
                    case '2': c = 1 ; break;
                    case '3': c = 2 ; break;
                }
                if (board[r][c] ==EMPTY){
                    board[r][c] = player;
                    break;
                }else{continue;}
            }else{continue;}
        }else{continue;}


    }
}


bool gameOver(char board[][COLS]){

    if ( (board[0][0]=='X') && (board[0][1]=='X') && (board[0][2]=='X')){
        cout << "Player X wins!";
        return true;
    }
    else  if ( (board[1][0]=='X') && (board[1][1]=='X') && (board[1][2]=='X')){
        cout << "Player X wins!";
        return true;
    }
    else  if ( (board[2][0]=='X') && (board[2][1]=='X') && (board[2][2]=='X')){
        cout << "Player X wins!";
        return true;
    }
    else  if ( (board[0][0]=='X') && (board[1][1]=='X') && (board[2][2]=='X')){
        cout << "Player X wins!";
        return true;
    }
    else  if ( (board[0][2]=='X') && (board[1][1]=='X') && (board[2][0]=='X')){
        cout << "Player X wins!";
        return true;
    }
    else  if ( (board[0][0]=='X') && (board[1][0]=='X') && (board[2][0]=='X')){
        cout << "Player X wins!";
        return true;
    }
    else  if ( (board[0][1]=='X') && (board[1][1]=='X') && (board[2][1]=='X')){
        cout << "Player X wins!";
        return true;
    }
    else  if( (board[0][2]=='X') && (board[1][2]=='X') && (board[2][2]=='X')){
        cout << "Player X wins!";
        return true;
    }
    if( (board[0][0]=='O') && (board[0][1]=='O') && (board[0][2]=='O')){
        cout << "Player O wins!";
        return true;
    }
    else  if( (board[1][0]=='O') && (board[1][1]=='O') && (board[1][2]=='O')){
        cout<<"Player O wins!";
        return true;
    }
    else  if( (board[2][0]=='O') && (board[2][1]=='O') && (board[2][2]=='O')){
        cout << "Player O wins!";
        return true;
    }
    else  if( (board[0][0]=='O') && (board[1][1]=='O') && (board[2][2]=='O')){
        cout<<"Player O wins!";
        return true;
    }
    else  if( (board[0][2]=='O') && (board[1][1]=='O') && (board[2][0]=='O')){
        cout << "Player O wins!";
        return true;
    }
    else  if( (board[0][0]=='O') && (board[1][0]=='O') && (board[2][0]=='O')){
        cout << "Player O wins!";
        return true;
    }
    else  if( (board[0][1]=='O') && (board[1][1]=='O') && (board[2][1]=='O')){
        cout << "Player O wins!";
        return true;
    }
    else  if( (board[0][2]=='O') && (board[1][2]=='O') && (board[2][2]=='O')){
        cout << "Player O wins!";
        return true;
    }

    if((board[0][0] != EMPTY ) && ( board[0][1] != EMPTY ) && ( board[0][2] != EMPTY ) && ( board[1][0] != EMPTY ) && ( board[1][1] != EMPTY ) && ( board[1][2] != EMPTY ) && ( board[2][0] != EMPTY ) && (board[2][1] != EMPTY ) &&( board[2][2] != EMPTY) ){
        cout<<"Tie!";
        return true;

    }


    return false;


}



// -----------------------------------------------------------------------
