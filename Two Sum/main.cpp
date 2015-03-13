
//Solve N Queens Problem
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;




bool isSafe(vector<vector<char> >&, int, int, char);

bool FindUnassign(vector<vector<char> >&, int&, int&);

void solveSudoku(vector<vector<char> > &board) {
    int row, col;
    
    if(!FindUnassign(board, row, col)) return;
    
    for(char num = '1'; num<'9';num++){
        if(isSafe(board, row, col, num)){
            board[row][col] = num;
            
            solveSudoku(board);
            if(!FindUnassign(board, row, col)) return;
            board[row][col] = '.';
        }
        
    }
    return;
}

bool FindUnassign(vector<vector<int> > & board, int& row, int& col){
    for(row = 0; row < board.size();row++){
        for(col = 0; col<board[row].size();col++){
            if(board[row][col]=='.') return true;
        }
        
    }
    return false;
}

bool UsedInCol(vector<vector<char> >&board, int col, char num){
    for(int row = 0;row< 9;row++){
        if(board[row][col]==num) return true;
    }
    return false;
}

bool UsedInRow(vector<vector<char> >&board, int row, char num){
    for(int col =0;col <9;col++){
        if(board[row][col]==num) return true;
    }
    return false;
}

bool UsedInBox(vector<vector<char> >&board, int row, int col,char num){
    int startrow = row/3 * 3;
    int startcol = col/3 * 3;
    
    for(int rowind = startrow;rowind<startrow+3;rowind++){
        for(int colind = startcol;colind<startrow+3;colind++){
            if(board[rowind][colind] == num) return true;
        }
    }
    return false;
}

bool isSafe(vector<vector<char> >& board, int row, int col, char num){
    if(!UsedInCol(board,col,num)
       &&!UsedInRow(board,row,num)
       &&!UsedInBox(board,row,col,num)) return true;
    
    else return false;
}

int main(){
    vector<vector<char> > board =
    {
        {'5','6','.','8','4','7','.','.','.'},
        {'3','.','9','.','.','.','6','.','.'},
        {'.','.','8','.','.','.','.','.','.'},
        {'.','1','.','.','8','.','.','4','.'},
        {'7','9','.','6','.','2','.','1','8'},
        {'.','5','.','.','3','.','.','9','.'},
        {'.','.','.','.','.','.','.','2','.'},
        {'.','.','6','.','.','.','8','.','7'},
        {'.','.','.','3','1','6','.','5','9'}
        
    };
    
    solveSudoku(board);
    return 0;
}