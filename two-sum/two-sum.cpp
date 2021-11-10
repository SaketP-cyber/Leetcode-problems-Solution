class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1,n1,n2;
 vector< int> v,nums2;
 nums2=nums;
 sort(nums2.begin(),nums2.end());
 while (low<high){
	 if (nums2[low]+nums2[high]<target) {
			 low++;
		 }
	 else if(nums2[low]+nums2[high]>target){
			 high--;
		 }
	 else{   //nums2[low]+nums2[high]==target
			 n1=nums2[low]; 
			 n2=nums2[high];
			 break;
 		} 
 	}
	
for (int i=0;i< nums.size() ; i++){
         if (nums[i]==n1)
         v.push_back(i);
         else if (nums[i]==n2)
         v.push_back(i);
		 }
		 return v;
		 }
    
};