class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int lo=0,hi=n-1,maxWater=INT_MIN;
        while(lo<hi){
            int w=hi-lo;
            int ht=min(height[lo],height[hi]);
            int currWater=w*ht;
            maxWater=max(currWater,maxWater);
            height[lo]<height[hi] ? lo++ : hi--;
        }
        return maxWater;
    }
};