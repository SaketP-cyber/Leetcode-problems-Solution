class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0,num=0;
        num=nums[0],cnt=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==num){
                cnt++;
            }
            else{
                cnt--;
                if(cnt==0){
                    num=nums[i];
                    cnt++;
                }
            }
        }
        return num;
    }
};