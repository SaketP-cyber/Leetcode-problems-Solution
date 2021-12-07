class RangeFreqQuery {
    private:
    vector<int>a;
    map<int,vector<int>>m1;
public:
    RangeFreqQuery(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){
            a.push_back(arr[i]);
        }
        for(int i=0;i<a.size();i++){
            m1[a[i]].push_back(i);
        }
    }
    int start(vector<int>&v,int num){
        int ind=lower_bound(v.begin(),v.end(),num)-v.begin();
            return ind;
    }
    int end(vector<int>&v,int num){
    return upper_bound(v.begin(),v.end(),num)-v.begin();
    }
    int query(int left, int right, int value) {
        if(m1.find(value)==m1.end())return 0;
        int startIndex=start(m1[value],left);
        int endIndex=end(m1[value],right);
        return endIndex-startIndex;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */