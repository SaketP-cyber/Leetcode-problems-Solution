class Solution {
public:
    vector<vector<string>>ans;
    bool isPalindrome(string s){
        string str=s;
        reverse(str.begin(),str.end());
        return s==str;
    }
    void solve(string s,vector<string>&temp,int ind,string str){
        if(ind>=s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=1;i<=s.size();i++){
            if(i+ind<=s.size() && isPalindrome( str+s.substr(ind,i))){
                temp.push_back(str+s.substr(ind,i));
                solve(s,temp,ind+i,str);
                temp.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        solve(s,temp,0,"");
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
};