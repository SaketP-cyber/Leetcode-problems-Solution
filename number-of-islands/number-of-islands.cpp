class Solution {
public:
    const int dirx [4]={0,0,1,-1};
    const int diry [4]={1,-1,0,0};
    bool isValid(int r,int c,int n,int m,vector<vector<char>>&grid){
        return (r>=0 && r<n && c>=0 && c<m && grid[r][c]=='1');
    }
    void dfs(int r,int c,int n,int m,vector<vector<char>>&grid){
        grid[r][c]='0';
        for(int i=0;i<4;i++){
            if(isValid(r+dirx[i],c+diry[i],n,m,grid)){
                dfs(r+dirx[i],c+diry[i],n,m,grid);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(i,j,n,m,grid);
                }
            }
        }
        return ans;
    }
};