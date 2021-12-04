class Solution {
public:
     vector<int> dp; 
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.assign(s.size(), -1); 
        return breakString(s, wordDict, 0); 
    }
    
    bool breakString(string &s, vector<string> &dict, int cur) {
        if (cur == s.size()) return true; 
        if (dp[cur] != -1) return dp[cur]; 
        
        bool rst = false; 
        for (int i = 0; i < dict.size(); i++) {
            if (dict[i] == s.substr(cur, dict[i].size())) {
                rst |= breakString(s, dict, cur+dict[i].size()); 
            }
        }
        dp[cur] = rst; 
        return rst; 
    }
};