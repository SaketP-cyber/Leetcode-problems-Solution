class Solution {
public:
    bool isBipartite(vector<vector<int>>& m1) {
        queue<int>q;
        int n=m1.size();
        vector<int>vis(n,0);
        for(int i=0;i<m1.size();i++){
            if(vis[i]==0){
            vis[i]=501;
            q.push(i);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto x:m1[node]){
                if(vis[x]==501 || vis[x]==502){
                    if(vis[node]==vis[x])return 0;
                }
                else{
                    if(vis[node]==501){
                        vis[x]=502;
                    }
                    else{
                        vis[x]=501;
                    }
                    q.push(x);
                }
            }
        }
        }
        }
        return 1;
    }
};