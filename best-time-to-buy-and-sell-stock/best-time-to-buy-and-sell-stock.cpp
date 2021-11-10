class Solution {
public:
    int maxProfit(vector<int>& a) {
     int buy=INT_MAX,sell=0,ans=0;
        buy=a[0];
        for(int i=1;i<a.size();i++){
            ans=max(a[i]-buy,ans);
            buy=min(a[i],buy);
        }
        return ans;
    }
};