#include <iostream>
#include <vector>
#include "Sudoku.h"

using namespace std;

void print_board(vector <int >);

int main()
{
    SudokuGen NewBoard; // 產生棋盤物件
    vector <int > board = NewBoard.get_board(); //取得棋盤
        print_board(board);

    NewBoard.generator(); // 產生新棋盤
    board = NewBoard.get_board();
        print_board(board);
 return 0;
}

void print_board(vector <int > board) //將棋盤印出
{
    for (int i=0;i<board.size();i++)
    {
        if(board[i]==0)
        {
                cout << "  ";
        }
        else
        {
                cout << board[i] << ' ';
        }
        if ((i+1) % 12 == 0)
        {
            cout << endl;
        }
    }
    cout << endl;
}
