class Solution {
public:
    
    int solve(int ind,vector<vector<int>>& events,int k,vector<vector<int>>&dp){
        if(ind>=events.size() || k==0)return 0;
        int i;
        if(dp[ind][k]!=-1)return dp[ind][k];
        for(i=ind+1;i<events.size();i++){
            if(events[ind][1]<events[i][0]){
                break;
            }
        }
        int a2=solve(ind+1,events,k,dp);
       int a1=events[ind][2]+solve(i,events,k-1,dp);
        
        return dp[ind][k]=max(a1,a2);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end(),[]
            (vector<int>&a,vector<int>&b){
                if(a[0]==b[0])return a[1]<b[1];
                return a[0]<b[0];
            }
            );
        int n=events.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
       
        return solve(0,events,k,dp);
    }
};