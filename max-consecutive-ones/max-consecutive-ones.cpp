class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0,n=nums.size();
        int i=0,j=0;
        while(i<=j && j<n){
            if(nums[i]==nums[j] && nums[i]==1){
                j++;
            }
            else{ j++;
                i=j;
               
            }
            ans=max(ans,j-i);
        }
        return ans;
    }
};