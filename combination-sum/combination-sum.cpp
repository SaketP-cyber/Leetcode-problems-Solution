class Solution {
public:
    void solve(vector<int>&nums,vector<vector<int>>&ans,vector<int>&temp,int n,int ind,int sum,int target){
         if(sum>target || ind==n){
            return;
        }
       
            if(sum==target){
                ans.push_back(temp);
                return;
            }
       
        temp.push_back(nums[ind]);
        solve(nums,ans,temp,n,ind,sum+nums[ind],target);
        temp.pop_back();
        solve(nums,ans,temp,n,ind+1,sum,target);
        
        }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
     sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        int n=nums.size();
        solve(nums,ans,temp,n,0,0,target);
        return ans;
    }
};