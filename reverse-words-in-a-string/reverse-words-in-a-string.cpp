class Solution {
public:
    string reverseWords(string s) {
        string ans="",str="";
        int ind=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                ind=i;
                break;
            }
        }
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==' ' ){
                if(str.size()>0){
                reverse(str.begin(),str.end());
                ans+=str;
                if(i>ind)
                ans+=' ';
                str="";}
            }
            else{
                str+=s[i];
            }
        }
        if(str.size()>0){
             reverse(str.begin(),str.end());
                ans+=str;
        }
        return ans;
    }
};