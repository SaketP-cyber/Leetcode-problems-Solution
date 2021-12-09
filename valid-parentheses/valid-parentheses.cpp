class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                st.push(s[i]);
            }
            else{
                if(s[i]==')'){
                    if(st.empty() || st.top()!='('){
                        return 0;
                    }
                    else{
                        st.pop();
                    }
                }
                else if(s[i]==']'){
                    if(st.empty() || st.top()!='['){
                        return 0;
                    }
                    else{
                        st.pop();
                    }
                }
                else{
                     if(st.empty() || st.top()!='{'){
                        return 0;
                    }
                    else{
                        st.pop();
                    }
                }
            }
         
        }
        if(st.empty())return 1;return 0;
           //return (st.empty==true);
    }
};