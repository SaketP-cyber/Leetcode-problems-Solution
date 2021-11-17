class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                   long long  num=target-(long long)nums[i]-(long long)nums[j]-(long long)nums[k];
                    int l=k+1,r=n-1;
                    int n1=INT_MAX;
                    while(l<=r){
                        int mid=(l+r)/2;
                        if((long long)nums[mid]==num){
                            n1=nums[mid];
                            break;
                        }
                        else if((long long)nums[mid]>num){
                            r=mid-1;
                        }
                        else{
                            l=mid+1;
                        }
                    }
                    if(n1!=INT_MAX){
                        ans.push_back({nums[i],nums[j],nums[k],n1});
                    }
                }
            }
        }
        sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};