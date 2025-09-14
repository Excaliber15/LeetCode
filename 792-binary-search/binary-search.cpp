class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Binary Search Algo
        int n=nums.size();
        int lo=0,hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target) return mid; // Element Found
            else if(target>nums[mid]) lo=mid+1;
            else hi=mid-1; // target<nums[mid]
        }
        return -1; // Element Not Found
    }
};