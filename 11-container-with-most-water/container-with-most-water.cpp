class Solution {
public:
    int maxArea(vector<int>& height) {
        // Two Pointer Technique
        int lo=0,hi=height.size()-1,maxWater=INT_MIN;
        while(lo<hi){
            int ht=min(height[lo],height[hi]);
            int w=hi-lo;
            int currWater=w*ht;
            maxWater=max(maxWater,currWater);
            height[lo]<height[hi] ? lo++ : hi--;
        }
        return maxWater;
    }
};