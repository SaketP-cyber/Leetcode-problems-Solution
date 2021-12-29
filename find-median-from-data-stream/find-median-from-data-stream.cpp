class MedianFinder {
public:
    priority_queue<int,vector<int>>maxheap;
    priority_queue<int,vector<int>,greater<int>>minheap;
    
    MedianFinder() {
    }
    
    void addNum(int num) {
        int l=maxheap.size();
        int r=minheap.size();
        if(l==r && l==0){
            maxheap.push(num);
        }
        else if(l==r){
            maxheap.push(num);
            if(maxheap.top()>minheap.top()){
                int x=maxheap.top();
                maxheap.pop();
                maxheap.push(minheap.top());
                minheap.pop();
                minheap.push(x);
            }
        }
        else{
            int x=maxheap.top();
            maxheap.pop();
            minheap.push(max(x,num));
            maxheap.push(min(x,num));
        }
    }
    
    double findMedian() {
         int l=maxheap.size();
        int r=minheap.size();
        if((l+r)&1){
            return (double)maxheap.top();
        }
        else{
            return ((double)maxheap.top()+(double)minheap.top())/(double)2;
        }
    
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */