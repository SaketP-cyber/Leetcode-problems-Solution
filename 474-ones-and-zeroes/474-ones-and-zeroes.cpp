class Solution {
private:
    int dp[601][101][101];
    public:
    
    int cnt(string s,bool isOne){
        int c=0;
        for(int i=0;i<s.size();i++){
            if(isOne && s[i]=='1'){
                c++;
            }
            if(!isOne && s[i]=='0')c++;
        }
        return c;
    }
    int solve(vector<string>&strs,int m,int n,int ind,int one,int zero){
        if(ind==strs.size()){
            return 0;
        }
        if(dp[ind][one][zero]!=-1)return dp[ind][one][zero];
        int o=cnt(strs[ind],1);
        int z=cnt(strs[ind],0);
        if(o+one<=n && z+zero<=m){
            return dp[ind][one][zero]= max(solve(strs,m,n,ind+1,one,zero),1+solve(strs,m,n,ind+1,o+one,z+zero));
        }
        else{
            return dp[ind][one][zero]=solve(strs,m,n,ind+1,one,zero);
        }
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(strs,m,n,0,0,0);
    }
};