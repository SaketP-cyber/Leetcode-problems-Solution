class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>m1;
        int i=0,j=0;
        int ans=0;
        while(i<=j && j<s.size()){
            if(m1.find(s[j])==m1.end()){
                m1[s[j]]++;  
            }
            else{
                while(s[i]!=s[j] && i<=j){
                    m1[s[i]]--;
                    if(m1[s[i]]==0){
                        m1.erase(s[i]);
                    }
                    i++;
                }
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};