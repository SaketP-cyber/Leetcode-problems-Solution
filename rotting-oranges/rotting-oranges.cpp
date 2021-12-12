class Solution {
public:
    int org=0;
    bool isValid(int x,int y,int n,int m,vector<vector<int>>& grid){
        if(x>=0 && x<n && y>=0 && y<m){
            if(grid[x][y]==1){org--;
            grid[x][y]=2;
        return 1;
                             }
        }
        return 0;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>rotten_oranges;
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    rotten_oranges.push({i,j});
                }
                else if(grid[i][j]==1)org++;
            }
        }
        //if(rotten_oranges.empty())return -1;
        int time=0;
        while(!rotten_oranges.empty() && org){
            time++;
            int qsz=rotten_oranges.size();
            for(int k=0;k<qsz && org;k++){
                int i=rotten_oranges.front().first;
                int j=rotten_oranges.front().second;
                rotten_oranges.pop();
                if(isValid(i+1,j,n,m,grid)){
                    rotten_oranges.push({i+1,j});
                }
                if(isValid(i,j+1,n,m,grid)){
                    rotten_oranges.push({i,j+1});
                }
                if(isValid(i-1,j,n,m,grid)){
                    rotten_oranges.push({i-1,j});
                }
                 if(isValid(i,j-1,n,m,grid)){
                   rotten_oranges.push({i,j-1});
                }
            }
        }
        if(org>0)return -1;
        return time;
    }
};