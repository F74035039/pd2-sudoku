#define SIZE 12
#include <vector>
using namespace std;

class SudokuGen
{
    public:
        SudokuGen();
        void generator(); //亂數法產生新棋盤 (初始化時建構子就會呼叫一次)
        vector<int > get_board(); //輸出棋盤至vector變數
        bool check_rep(vector<int>,int,int); //偵測填入數字是否重複、符合規則，不符合>會回傳false值
        bool board_put(vector<int>&); //填入數字函式，嘗試失敗超過1000次會回傳false值
        SudokuGen(vector < int >, int); //建構子
        void board_dig(int); //挖洞函式
        void copy_board(); //複製棋盤函式
        vector<int> gets_board();
    private:
        int new_board[SIZE][SIZE]; //棋盤
        int i,j,k,l; //迴圈用變數
        int in_board[SIZE][SIZE]; //輸入棋盤
        int dig_board[SIZE][SIZE]; //輸出棋盤(挖完洞)
        int number_seres[SIZE*SIZE]; //數字序列
};
