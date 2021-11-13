class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // if(nums.size()<=2)return nums;
        int c1=0,n1=INT_MAX,c2=0,n2=INT_MAX;
        // n1=nums[0],n2=nums[ind],c1=1,c2=1;
        for(int i=0;i<nums.size();i++){
            if(n1==nums[i])c1++;
            else if(n2==nums[i])c2++;
            else if(c1==0){
                n1=nums[i];
                c1=1;
            }
            else if(c2==0){
                n2=nums[i];
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        c1=0,c2=0;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==n1)c1++;
            if(nums[i]==n2)c2++;
        }
        if(c1>nums.size()/3){
            ans.push_back(n1);
        }
        if(c2>nums.size()/3){
            ans.push_back(n2);
        }
        return ans;
    }
};