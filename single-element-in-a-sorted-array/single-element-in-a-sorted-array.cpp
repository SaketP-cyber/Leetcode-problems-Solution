class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=n-1;
        int ans=-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(mid-1>=0 && nums[mid]==nums[mid-1]){
                if((mid+1)%2==0){
                    i=mid+1;
                }
                else{
                    j=mid-2;
                }
            }
            else if(mid+1<n && nums[mid]==nums[mid+1]){
                if((n-mid)%2){
                    i=mid+2;
                }
                else{
                    j=mid-1;
                }
            }
            else{
                ans=nums[mid];
                break;
            }
        }
        return ans;
    }
};