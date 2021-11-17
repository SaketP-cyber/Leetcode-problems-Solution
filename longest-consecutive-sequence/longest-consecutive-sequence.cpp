class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>m1,m2;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m1[nums[i]]=nums[i];
        }
        for(auto x:m1){
            if(m1.find(x.first-1)!=m1.end()){
                m1[x.second]=m1[x.first-1];
            }
        }
        int ans=0;
        for(auto x:m1){
            m2[x.second]++;
            ans=max(ans,m2[x.second]);
        }
        return ans;
    }
};