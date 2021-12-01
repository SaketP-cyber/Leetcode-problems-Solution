class Solution {
public:
    bool isValid(vector<string>&temp,int r,int c,int n){
        int row=r;
        int col=c;
        while(col>=0){
            if(temp[row][col]=='Q'){
                return 0;
            }
            col--;
        }
        col=c;
        while(row>=0 && col>=0){
            if(temp[row][col]=='Q'){
                return 0;
            }
            col--;row--;
        }
        col=c;
        row=r;
        while(row<n && col>=0){
             if(temp[row][col]=='Q'){
                return 0;
            }
            col--;row++;
        }
        return 1;
    }
    void solve(vector<vector<string>>&grid,vector<string>&temp,int c,int n){
        if(c==n){
            grid.push_back(temp);
            return ;
        }
        for(int i=0;i<n;i++){
            if(isValid(temp,i,c,n)){
                temp[i][c]='Q';
                solve(grid,temp,c+1,n);
                temp[i][c]='.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>grid;
        string s="";
        for(int i=0;i<n;i++){
            s+='.';
        }
        vector<string>temp(n,s);
        solve(grid,temp,0,n);
        return grid;
    }
};