class Solution {
public:
    int dp[501][501];
    int solve(string word1, string word2,int i,int j){
        int n=word1.size(),m=word2.size();
        if(j>=m){
            return n-i;
        }
        if(i>=n)return m-j;
        if(dp[i][j]!=-1)return dp[i][j];
        if(word1[min(i,n-1)]==word2[min(j,m-1)]){
            return dp[i][j]= solve(word1,word2,i+1,j+1);
        }
        return dp[i][j]= 1+min({solve(word1,word2,i+1,j),solve(word1,word2,i,j+1),solve(word1,word2,i+1,j+1)});
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return solve(word1,word2,0,0);
    }
};
