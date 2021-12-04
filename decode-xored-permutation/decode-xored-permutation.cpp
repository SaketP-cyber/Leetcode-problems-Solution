class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int x=0;
        int n=encoded.size();
        n++;
        for(int i=1;i<=n;i++)x^=i;
        int x1=0;
        for(int i=0;i<n-1;i+=2){
            x1^=encoded[i];
        }
        int last_num=x^x1;
        n--;
        vector<int>ans;
        ans.push_back(last_num);
        for(int i=n-1;i>=0;i--){
            ans.push_back(last_num^encoded[i]);
            last_num=last_num^encoded[i];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};