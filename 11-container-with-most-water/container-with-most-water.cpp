class Solution {
public:
    int maxArea(vector<int>& height) {
        // Two Pointers Technique
        int n=height.size();
        int lo=0,hi=n-1;
        int maxWater=INT_MIN;
        while(lo<hi){
            int ht=min(height[lo],height[hi]); // max height of water col
            int w=hi-lo; // width of water column
            int currWater=w*ht;
            maxWater=max(maxWater,currWater);
            height[lo]<height[hi] ? lo++ : hi--;
        }
        return maxWater;
    }
};