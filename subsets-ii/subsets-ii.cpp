class Solution {
public:
    void solve(vector<int>& nums,int n,vector<vector<int>>&ans,vector<int>&temp,int ind){
        if(ind ==n){
            ans.push_back(temp);
            return;
        }
        solve(nums,n,ans,temp,ind+1);
        temp.push_back(nums[ind]);
        solve(nums,n,ans,temp,ind+1);
        temp.pop_back();
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n=nums.size();
        solve(nums,n,ans,temp,0);
        for(int i=0;i<ans.size();i++){
            sort(ans[i].begin(),ans[i].end());
        }
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
};