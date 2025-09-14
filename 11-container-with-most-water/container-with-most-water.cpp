class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int lo=0,hi=n-1,maxWater=0;
        while(lo<hi){
            int w=hi-lo;
            int ht=min(height[lo],height[hi]);
            int currWater=w*ht;
            maxWater=max(maxWater,currWater);
            height[lo]<height[hi] ? lo++ : hi--;
        }
        return maxWater;
    }
};