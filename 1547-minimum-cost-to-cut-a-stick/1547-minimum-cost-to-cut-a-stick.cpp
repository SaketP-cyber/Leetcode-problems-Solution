class Solution {
public:
    int dp[101][101];
    int solve(int n,vector<int>&cuts,int l,int r){
        if(l>=r){
            return 0;
        }
        if(dp[l][r]!=-1)return dp[l][r];
        int ans=1e9;
        for(int i=l;i<r;i++){
            int lft=(l==0)?0:cuts[l-1];
            int rght=(r==cuts.size())?n:cuts[r];
            ans=min(ans,(rght-lft)+solve(lft,cuts,l,i)+solve(rght,cuts,i+1,r));
        }
        return dp[l][r]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        sort(cuts.begin(),cuts.end());
       return solve(n,cuts,0,cuts.size());
    }
};