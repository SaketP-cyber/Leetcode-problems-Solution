class Solution {
public:
     vector<vector<int>>ans;
    void solve(vector<int>&nums,int ind,int n){
        if(ind==nums.size()-1){
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<n;i++){
            swap(nums[ind],nums[i]);
            solve(nums,ind+1,n);
           swap(nums[ind],nums[i]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        solve(nums,0,n);
        return ans;
    }
};