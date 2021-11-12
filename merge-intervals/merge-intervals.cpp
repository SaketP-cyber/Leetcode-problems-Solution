class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        int n=a.size();
        sort(a.begin(),a.end());
        vector<vector<int>>ans;
        int mini=a[0][0];
        int maxi=a[0][1];
        for(int i=1;i<n;i++){
            if(a[i][0]<=maxi && a[i][0]>=mini){
                maxi=max(maxi,a[i][1]);
            }
            else{
                ans.push_back({mini,maxi});
                mini=a[i][0];
                maxi=a[i][1];
            }
        }
        ans.push_back({mini,maxi});
        return ans;
    }
};