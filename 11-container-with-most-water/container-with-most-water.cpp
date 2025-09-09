class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int lo=0;
        int hi=n-1;
        int maxWater=INT_MIN;
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