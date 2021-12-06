class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n1=nums1.size(),n2=nums2.size();
        // if(n1==1 && n2==0){
        //     return (double)nums1[0];
        // }
        // if(n2==1 && n1==0){
        //     return (double)nums2[0];
        // }
        if(n1>n2){
            return findMedianSortedArrays(nums2,nums1);
        }
        int i=0,j=n1;
        while(i<=j){
            int c1=(i+j)/2;
            int c2=((n1+n2+1)/2)-c1;
            int l1=(c1==0)?INT_MIN:nums1[c1-1];
            int l2=(c2==0)?INT_MIN:nums2[c2-1];
            int r1=(c1==nums1.size())?INT_MAX:nums1[c1];
            int r2=(c2==nums2.size())?INT_MAX:nums2[c2];
            if(l1<=r2 && r1>=l2){
                if((n1+n2)%2){
                    return max((double)l1,(double)l2);
                }
                else{
                    return (max((double)l1,(double)l2)+min((double)r2,(double)r1))/2.00;
                }
            }
            else if(l2>=r1){
                i=c1+1;
            }
            else{
                j=c1-1;
            }
        }
        return 0.0;
    }
};