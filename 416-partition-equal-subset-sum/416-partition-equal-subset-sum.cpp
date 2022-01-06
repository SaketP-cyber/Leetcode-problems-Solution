class Solution {
public:
    bool solve(vector<int>&nums,int sum,int ind,int tsum, vector<vector<int>>&dp){
        if(ind==nums.size())return 0;
        if(sum==tsum/2){
            return 1;
        }
        if(dp[ind][sum]!=-1)return dp[ind][sum];
        return dp[ind][sum]=solve(nums,sum+nums[ind],ind+1,tsum,dp) || solve(nums,sum,ind+1,tsum,dp);
    }
    bool canPartition(vector<int>& nums) {
        int tsum=0;
        for(int i=0;i<nums.size();i++){
            tsum+=nums[i];
        }
        if(tsum%2!=0)return 0;
        vector<vector<int>>dp(nums.size(),vector<int>(tsum,-1));
        return solve(nums,0,0,tsum,dp);
    }
};