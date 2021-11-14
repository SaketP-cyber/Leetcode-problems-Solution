class Solution {
public:
    int merge(vector<int>&nums,int l,int r,int mid){
        int i=l,j=mid+1;
        int cnt=0;
        vector<int>ans;
         while(i<=mid && j<=r){
            if((long long)nums[i]>(long long)2*(long long )nums[j]){
                cnt+=((mid-i)+1);
                j++;
            }
             else
                 i++;
             
         }  
        i=l,j=mid+1;
        while(i<=mid && j<=r){
            if(nums[i]>nums[j]){
                ans.push_back(nums[j]);
                j++;
            }
            else{
                ans.push_back(nums[i]);
                i++;
            }
        }
        while(i<=mid){
            ans.push_back(nums[i]);
            i++;
        }
        while(j<=r){
            ans.push_back(nums[j]);
            j++;
        }
        int a=0;
        for(int k=l;k<=r;k++){
            nums[k]=ans[a];
            a++;
        }
        return cnt;
    }
    int solve(vector<int>&nums,int l,int r){
        if(l>=r)return 0;
        int mid=(l+r)/2;
        int left=solve(nums,l,mid);
        int right=solve(nums,mid+1,r);
        return merge(nums,l,r,mid)+left+right;
    }
    int reversePairs(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};