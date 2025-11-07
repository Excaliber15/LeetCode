class Solution {
public:
    int maxArea(vector<int>& height) {
        // Two Pointers Techique
        int n=height.size();
        int lo=0,hi=n-1,maxWater=INT_MIN;
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