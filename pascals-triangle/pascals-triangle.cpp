class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>a(n);
         for(int i=0;i<n;i++){
            vector<int>b(i+1);
            b[0]=1;
            b[i]=1;
            for(int j=1;j<i;j++){
                b[j]=a[i-1][j]+a[i-1][j-1];        
            }
             a[i]=b;
        }
        return a; //ans
    }
};
