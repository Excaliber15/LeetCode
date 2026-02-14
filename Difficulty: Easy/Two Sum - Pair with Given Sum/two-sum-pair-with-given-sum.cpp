class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        sort(arr.begin(),arr.end());
        int lo=0;
        int hi=arr.size()-1;
        while(lo<hi){
            int currSum=arr[lo]+arr[hi];
            if(currSum==target) return true; // Pair Sum Found
            else if(currSum>target) hi--;
            else lo++; // currSum<target
        }
        return false; // pair sum not found
    }
};