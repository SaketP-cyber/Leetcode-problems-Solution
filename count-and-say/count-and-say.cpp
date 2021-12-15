class Solution {
public:
    string solve(string s){
        map<char,int>m1;
        int n=s.size();
        for(int i=0;i<n;i++){
            m1[s[i]]++;
        }
        string str="";
      int i=0,j=0;
        while(j<n){
            if(s[i]==s[j]){
                j++;
            }
            else{
                str+=to_string(j-i)+s[i];
                i=j;
            }
        }
        if(i!=j){
             str+=to_string(j-i)+s[i];
        }
        return str;
    }
    string countAndSay(int n) {
        string str="1";
        for(int i=1;i<n;i++){
            str=solve(str);
        }
        return str;
    }
};