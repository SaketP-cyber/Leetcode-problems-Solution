class Solution {
public:
    bool isValid(vector<vector<char>>& board,int r,int c,char k){
        for(int i=0;i<9;i++){
            if(board[r][i]==k){
                return 0;
            }
            if(board[i][c]==k){
                return 0;
            }
        }
        for(int i=0;i<9;i++){
            if(board[3*(r/3)+i/3][3*(c/3)+i%3]==k)return 0;
        }
        return 1;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char c='1' ;c<='9';c++){
                        if(isValid(board,i,j,c)){
                            board[i][j]=c;
                            if(solve(board)){
                                return 1;
                            }
                            else{
                                board[i][j]='.';
                            }
                        }
                    }
                    return 0;
                }
            }
        }
        return 1;
    }
    void solveSudoku(vector<vector<char>>& board) {
         solve(board);
        return ;
    }
};