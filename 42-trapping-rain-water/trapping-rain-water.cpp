class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int lo=0;
        int hi=n-1;
        int lmax=0,rmax=0,ans=0;
        while(lo<hi){
            lmax=max(lmax,height[lo]);
            rmax=max(rmax,height[hi]);
            if(lmax<rmax){
                ans+=lmax-height[lo];
                lo++;
            }
            else{
                ans+=rmax-height[hi];
                hi--;
            }
        }
        return ans;
    }
};