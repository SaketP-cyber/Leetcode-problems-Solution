class Solution {
public:
   string keypad[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
vector<string>ans;
void solve(int n,string &digits,int ind,string &temp){
    if(temp.size()==n){
        ans.push_back(temp);
        return;
    }
    for(int i=0;i<keypad[digits[ind]-'0'].size();i++){
        temp.push_back(keypad[digits[ind]-'0'][i]);
        solve(n,digits,ind+1,temp);
        temp.pop_back();
    }
}
vector<string> letterCombinations(string digits) {
    int n=digits.size();
    if(n==0){
        return {};
    }
    string temp="";
    solve(n,digits,0,temp);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    return ans;
}
};