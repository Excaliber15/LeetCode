class Solution {
public:
    void printAllSubsets(vector<int>& nums,vector<vector<int>>&ans,vector<int>&v,int i){
        // base case
        if(i>=nums.size()){
            ans.push_back(v);
            return;
        }
        // include ans
        v.push_back(nums[i]);
        printAllSubsets(nums,ans,v,i+1);
        v.pop_back(); // backTrack
        // exclude ans
        printAllSubsets(nums,ans,v,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        int index=0;
        printAllSubsets(nums,ans,v,index);
        return ans;
    }
};