class Solution {
public:
    double power(double x,long long n){
        double ans=1.0;
        while(n){
            if(n%2){
                ans*=x;n--;
                if(n>0){
                     x=x*x;n/=2;
                }
            }
            else{
                x=x*x;n/=2;
            }
            
        }
        return ans;
    }
    double myPow(double x, int n) {
        if(x==double(1))return double(1);
       int sign=1;
        if(n<0)
            sign=-1;
        n=(long long)abs(n);
        double ans=power(x,n);
        if(sign==-1){
            return 1.0/ans;
        }
        return ans;
    }
};