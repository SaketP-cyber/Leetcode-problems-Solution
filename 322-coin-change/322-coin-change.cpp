class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        sort(coins.begin(),coins.end());
        vector<vector<long long>>dp(n+1,vector<long long>(amount+1,0));
        for(int i=1;i<=amount;i++){
            dp[0][i]=1e10;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
                }
            }
        }
        if(dp[n][amount]>=1e10)return -1;
        return (int)dp[n][amount];
    }
};