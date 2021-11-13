class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool ans=0;
        int i=0,j=matrix[0].size()-1;
        while(i<matrix.size() && j>=0){
            if(matrix[i][j]==target){
                ans=1;break;
            }
            else if(matrix[i][j]>target){
                j--;
            }
            else
                i++;
        }
        return ans;
    }
};