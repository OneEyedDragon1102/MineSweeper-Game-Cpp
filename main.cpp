#include<bits/stdc++.h>
#define nl cout<<"\n"
using namespace std;


int MINES, COL, ROW;

void setMines(vector <vector <char>> &realBoard){
    int k = 0;
    while(k < MINES){
        int x = rand() % ROW;
        int y = rand() % COL;

        if(realBoard[x][y] != '*'){
            realBoard[x][y] = '*';
            k++;
        }
    }

}

void printBoard(vector <vector <char>> &playingBoard, int MOVES){
    cout<<"Mines : "<<MINES;nl;
    cout<<"Moves : "<<MOVES;nl;
     
    cout<<"    ";
    for (int i = 0; i < ROW; i++){
        if(i < 8){
            cout<<i+1<<"  ";
        }
        else{
            cout<<i+1<<" ";
        }
    }
    nl;nl;
 
    for (int i = 0; i < ROW; i++){
        if(i < 9){
            cout<<i+1<<"   ";
        }
        else{
            cout<<i+1<<"  ";
        }
        for (int j = 0; j <COL; j++){
            cout<<playingBoard[i][j]<<"  ";
        }nl;
    }
}

void play(){
    bool gameplay = true; // while the game is being played and not over
    vector <vector <char> > realBoard(ROW, vector <char> (COL, '-')), playingBoard(ROW,vector <char> (COL, '-'));

    int MOVES = (ROW * COL) - MINES, x, y; 

    setMines(realBoard);

    while(gameplay){
        printBoard(playingBoard, MOVES);
        break;
    }
}

void chooseLevel(){
    int level;
    cout<<"Choose Difficulty Level : \n";
    cout<<"1 : Easy\t2 : Medium\t3 : Hard\n\n";
    cout<<"Enter Difficulty : ";
    cin>>level;

    switch (level)
    {
        case 1 : 
            MINES = 10;
            ROW = 9;
            COL = 9;
            break;
    
        case 2 :
            MINES = 40;
            ROW = 16;
            COL = 16;
            break;

        case 3 :
            MINES = 99;
            ROW = 24;
            COL = 24;
            break;

        default:
            cout<<"Enter Valid Dificulty Level\n\n";
            chooseLevel();
            break;
    }
}

int main()
{
    chooseLevel();
    play();
    return 0;
}