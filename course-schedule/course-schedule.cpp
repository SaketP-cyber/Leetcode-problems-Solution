class Solution {
public:
    bool dfs(int node,map<int,vector<int>>&m1,vector<bool>&vis,vector<bool>&dfsVis){
        vis[node]=1;
        dfsVis[node]=1;
        bool ans=1;
        for(auto x:m1[node]){
            if(vis[x] && dfsVis[x])ans= 0;
            else if(vis[x]==0){
                ans&=dfs(x,m1,vis,dfsVis);
            }
        }
        dfsVis[node]=0;
        return ans;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,vector<int>>m1;
        for(int i=0;i<prerequisites.size();i++){
            m1[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<bool>vis(numCourses,0),dfsVis(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(!dfs(i,m1,vis,dfsVis))return 0;
            }
        }
        return 1;
    }
};