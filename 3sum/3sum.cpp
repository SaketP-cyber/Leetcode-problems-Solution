class Solution {
public:
    bool check(vector<int>&nums,int l,int r,int t){
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==t){
                return 1;
            }
            else if(nums[mid]>t){
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return 0;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<=2)return {};
        sort(nums.begin(),nums.end());
       set<vector<int>>ans;
        for(int i=0;i<nums.size()-2;i++){
            int l=i+1,r=nums.size()-1;
            while(l<r){
                if(nums[i]+nums[r]+nums[l]==0){
                    ans.insert({nums[i],nums[l],nums[r]});
                l++;r--;
                }
                else if(nums[i]+nums[r]+nums[l]>0){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        vector<vector<int>>a;
        for(auto x:ans){
            a.push_back(x);
        }
        return a;
    }
};