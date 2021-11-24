class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=0,k=0;
        int n=nums.size();
        if(n<=1){
            return n; 
        }
        while(i<=j && j<n-1){
            if(nums[j+1]==nums[j]){
                j++;
            }
            else{
                nums[i]=nums[j];
                i++;
                j++;
                k++;
            }
        }
        nums[i]=nums[j];
        k++;
        return k;
    }
};