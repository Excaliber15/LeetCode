class Solution {
public:
    int mySqrt(int x) {
        int lo=0,hi=x,ans=-1;
        while(lo<=hi){
            long long int mid=lo+(hi-lo)/2;
            if(mid*mid==x) return mid;
            else if(mid*mid<x){
                ans=mid; // store
                lo=mid+1; // compute
            }
            else hi=mid-1; // mid*mid>x
        }
        return ans;
    }
};