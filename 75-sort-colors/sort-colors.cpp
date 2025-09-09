class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int lo=0,hi=n-1,mid=0;
        while(mid<=hi){
            if(nums[mid]==2){
                swap(nums[mid],nums[hi]);
                hi--;
            }
            else if(nums[mid]==0){
                swap(nums[mid],nums[lo]);
                lo++;
                mid++;
            }
            else{ // nums[mid]==1
                mid++;
            }
        }
    }
};