class Solution {
public:
    int maxProfit(vector<int>& a) {
     int buy1=INT_MAX,sell=0,ans=0;
        buy1=a[0];
        for(int i=1;i<a.size();i++){
            ans=max(a[i]-buy1,ans);
            buy1=min(a[i],buy);
        }
        return ans;
    }
};
