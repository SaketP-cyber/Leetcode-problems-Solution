class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0],maxi=nums[0],mini=nums[0];
        for(int i=1;i<nums.size();i++){
            int t=maxi;
            maxi=max(nums[i],max(t*nums[i],mini*nums[i]));
            mini=min(nums[i],min(t*nums[i],mini*nums[i]));
            ans=max(ans,maxi);
            if(nums[i]==0){
                maxi=1;
                mini=1;
            }
        }
        return ans;
    }
};