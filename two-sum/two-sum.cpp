class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
  set<int>s;
        s.insert(nums[0]);
        int num;
        vector<int>ans;
        for(int i=1;i<nums.size();i++){
            if(s.count(target-nums[i])){
                num=target-nums[i];
                ans.push_back(i);
                break;
            }
            s.insert(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==num){
                ans.push_back(i);
                break;
            }
        }
        return ans;
		 }
    
};