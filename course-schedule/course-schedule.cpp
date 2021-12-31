class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>a;
        map<int,vector<int>>m1;
        for(auto x:prerequisites){
            m1[x[0]].push_back(x[1]);
        }
        
        vector<int>indeg(numCourses,0);
        for(auto x:m1){
            for(auto j:x.second)
            indeg[j]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0)q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            a.push_back(node);
            for(auto x:m1[node]){
                indeg[x]--;
                if(indeg[x]==0)q.push(x);
            }
        }
        if(a.size()==numCourses){
            return 1;
        }
        return 0;
    }
};