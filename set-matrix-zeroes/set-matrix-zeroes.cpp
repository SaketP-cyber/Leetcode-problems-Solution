class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int>r,c;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    r.insert(i);
                    c.insert(j);
                }
            }
        }
        for(auto x:r){
            for(int i=0;i<m;i++){
                matrix[x][i]=0;
            }
        }
        for(auto x:c){
            for(int i=0;i<n;i++){
                matrix[i][x]=0;
            }
        }
        
    }
};