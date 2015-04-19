#include "Sudoku.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

SudokuGen::SudokuGen() // 建構子(Constructor)
{
    srand(time(NULL)); //以物件初始化時間設定為亂數種子
    generator(); //以亂數方法產生數獨棋盤
}

void SudokuGen::generator() //亂數法產生新棋盤
{
    int i,a,b,c,d;
    int tmp; //置換用暫存變數
    int numtmp[9] = {1,2,3,4,5,6,7,8,9}; //9宮格內的數字
    vector <int> board(144); //棋盤
    bool check = false; //表示棋盤是否成功產生

    for (i=0;i<144;i++)
        {
                board[i] = 0;
 } //初始化棋盤(填入0)

        do{
                a=rand()%10;
        }while(a%3!=0);
        for(i=0;i<36;i+=12)
        {
                board[a+i]=-1;
                board[a+i+1]=-1;
                board[a+i+2]=-1;
        }
        do{
                b=rand()%10;
        }while(b%3!=0||b==a);
        for(i=0;i<36;i+=12)
        {
                board[b+36+i]=-1;
                board[b+36+i+1]=-1;
                board[b+36+i+2]=-1;
        }
        do{
                c=rand()%10;
        }while(c%3!=0||c==a||c==b);
        for(i=0;i<36;i+=12)
  {
                board[c+72+i]=-1;
                board[c+72+i+1]=-1;
                board[c+72+i+2]=-1;
        }
        do{
                d=rand()%10;
        }while(d%3!=0||d==a||d==b||d==c);
        for(i=0;i<36;i+=12)
        {
                board[d+108+i]=-1;
                board[d+108+i+1]=-1;
                board[d+108+i+2]=-1;
        }

        if(board[0]<0)
        {
                for (i=0;i<9;i++)
                {
                        board[i/3*12+i%3+3] = numtmp[i];
                }
        }
        else
        {
 for (i=0;i<9;i++)
                {
                        board[i/3*12+i%3] = numtmp[i];
                }
        }
        while(!check) //不斷嘗試直到符合規則的棋盤產生
        {
//        填入數字函式，嘗試失敗超過1000次會回傳false值
                check = board_put(board);
        }

        for (i=0;i<9;i++) //將1-9的數字順序打亂
        {
                j = rand() % 9;
                tmp = numtmp[i];
                numtmp[i] = numtmp[j];
                numtmp[j] = tmp;
        }

        for(i=0;i<144;i++) //將棋盤的數字序置換為新產生的數字序
        {
                if(board[i]<0)
                continue;
                board[i] = numtmp[board[i]-1];
 }

    for (i=0;i<SIZE;i++) //將結果寫入new_board變數
        for (j=0;j<SIZE;j++)
        {
            new_board[i][j] = board[i*SIZE+j];
        }

}

vector <int > SudokuGen::get_board() //輸出棋盤至vector變數
{
    vector < int > out_board (SIZE*SIZE);
    for (i=0;i<SIZE;i++)
        for (j=0;j<SIZE;j++)
        {
            out_board[i*SIZE+j] = new_board[i][j];
        }
    return out_board;
}

bool SudokuGen::check_rep(vector<int> board,int pos,int n)
{
    int i;
for (i=0;i<12;i++)
    {
        if(board[pos/12*12+i]==n) //check橫排上數字是否有重複
        {
            return true; //有重複，回傳true
        }
        if(board[i*12+pos%12]==n) //check直排上數字是否有重複
        {
            return true; //有重複，回傳true
        }
    }
    return false;  //無重複，回傳false
}

bool SudokuGen::board_put(vector<int > &board) //填入數字函式
{
    int pos;
    int count1,count2; //計數器
    bool check = true; //check數字是否重複

    for (j=0;j<9;j++) //填入的數字1-9 (j+1的結果)
    {
        count2 = 0; //計算單一數字填入總共甞試錯誤次數
        for (i=1;i<16;i++) //依序將數字填入其餘十五個小九宮格(左上角已經產生)
{
                pos = i/4*36+i%4*3; //每個小九宮格的起始inde
                if(board[pos]<0)
                continue;
                        count1 = 0; //計算單一數字填入甞試錯誤次數
                        while (check==true)
                        {
                                k = rand() % 9;
                                check = check_rep(board,pos+k/3*12+k%3,j+1);
                                ++count1;
                                ++count2;
                                if (board[pos+k/3*12+k%3]==0 && check==false) //數字沒
有重複，成功填入結束while loop
                                {
                                        board[pos+k/3*12+k%3] = j+1;
                                        check = true;
                                        break;
                                }
                                else
                                {
                                        check = true;
                                }
                                if (count1 > 100) // 錯誤超過100次，數字重填
                                {
 for (l=0;l<144;l++)
                                        {
                                                if (board[l]==j+1)
                                                {
                                                        board[l]=0;
                                                }
                                        }
                                        board[j/3*12+j%3]=j+1;
                                        i = 0;
                                        break;
                                }
                                if (count2 > 1000) // 錯誤超過1000次，回傳false並結束>函式
                                {
                                        return false;
                                }
                         }
        }
    }
    return true; //成功填滿棋盤，回傳true
}
