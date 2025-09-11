class Solution {
public:
    int getQuotient(long long int dividend, long long int divisor){
        long long int lo=-dividend,hi=dividend,ans=-1;
        while(lo<=hi){
            long long int mid=lo+((hi-lo)>>1);
            if(divisor*mid==dividend) return mid;
            else if(divisor*mid<dividend){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1; // divisor*mid>dividend
        }
        return ans;
    }
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        long long int ans=getQuotient(llabs(dividend),llabs(divisor));
        if((dividend<0 && divisor>0) || (dividend>0 && divisor<0)){
            ans=0-ans;
        }
        return ans;
    }
};