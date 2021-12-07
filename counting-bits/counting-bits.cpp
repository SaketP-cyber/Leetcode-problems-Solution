class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
     for(int i=0;i<=n;i++){
         int cnt=0,a=i;
         while(a){
             cnt++;
             a=(a&(a-1));
         }
         ans.push_back(cnt);
     }
        return ans;
    }
};