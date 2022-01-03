class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=n*nums[i];
        }
        for(int i=0;i<n;i++){
            int ind=nums[i]/n;
            nums[i]+=(nums[ind]/n);
        }
        for(int i=0;i<n;i++){
            nums[i]%=n;
        }
        return nums;
    }
};