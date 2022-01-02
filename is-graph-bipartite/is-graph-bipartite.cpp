class Solution {
public:
    bool dfs(int ind,vector<vector<int>>&m1,vector<int>&vis){
        //vis[ind]=1;
        bool ans=1;
        for(auto x:m1[ind]){
            if(vis[x]!=0){
                if(vis[ind]==vis[x])ans=0;
            }
            else{
                if(vis[ind]==501){
                    vis[x]=502;
                }
                else{
                    vis[x]=501;
                }
                ans&=dfs(x,m1,vis);
            }
        }
        return ans;
    }
    bool isBipartite(vector<vector<int>>& m1) {
        int n=m1.size();
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                vis[i]=501;
                if(!dfs(i,m1,vis)){
                    return false;
                }
            }
        }
        return 1;
    }
};