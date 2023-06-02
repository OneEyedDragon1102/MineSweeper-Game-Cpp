#include<bits/stdc++.h>
#include<conio.h>
#define nl cout<<"\n"
using namespace std;


int MINES, COL, ROW;

bool isMine(int &x, int &y, vector <vector <char>> &realBoard){
    if(realBoard[x-1][y-1] == '*'){
        return true;
    }

    return false;
}

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
    cout<<"\nStatus of Board : \n";
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

void userMove(int &x, int &y, bool z){
    cout<<"\n1. Input";
    cout<<"\n2. Flag a mine";
    cout<<"\n3. Exit";
    cout<<"\n>>";    
    int n;
    cin>>n;
    switch (n)
    {
    case 1:
        initRow:
        cout<<"Enter row number : ";
        cin>>x;
        if(x < 1 || x > ROW){
            cout<<"Row out of bounds\n";
            goto initRow;
        }
        initCol:
        cout<<"Enter column number : ";
        cin>>y;
        if(y < 1 || y > COL){
            cout<<"Row out of bounds\n";
            goto initCol;
        }
        break;
    
    default:
        break;
    }
}

void replaceMine(int &x, int &y, vector <vector <char>> &realBoard){
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            if(realBoard[i][j] != '*'){
                realBoard[i][j] = '*';
                realBoard[x][y] = '-';
                return;
            }
        }
    }
}

void play(){
    bool gameplay = true; // while the game is being played and not over
    vector <vector <char> > realBoard(ROW, vector <char> (COL, '-')), playingBoard(ROW,vector <char> (COL, '-'));

    int MOVES = 0, x, y; 

    setMines(realBoard);
    while(gameplay){
        printBoard(playingBoard, MOVES);
        
        int x, y, z = 0;
        userMove(x, y, gameplay);
        if(z == false){
            cout<<"\nThanks for playing :)";
            break;
        }

        if(MOVES == 0){
            if(isMine(x, y, realBoard)){
                replaceMine(x, y, realBoard);
            }
        }

        MOVES++;
        
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