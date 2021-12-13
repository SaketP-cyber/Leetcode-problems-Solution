class Solution {
public:
    string longestPalindrome(string s) {
        int max_len=0;
        int n=s.size();
        int start=0;
        for(int i=0;i<n;i++){
            int l=i,r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                 if(max_len<r-l+1){
                max_len=r-l+1;
                start=l;
            }
                l--;
                r++;
            }
           
            //max_len=max(max_len,r-l+1);
        }
        for(int i=0;i<n;i++){
            int l=i,r=i+1;
             while(l>=0 && r<n && s[l]==s[r]){
                  if(max_len<r-l+1){
                max_len=r-l+1;
                start=l;
            }
                l--;
                r++;
            }
           
        }
        return s.substr(start,max_len);
    }
};