class Solution {
public:
    void printAllSubsets(vector<int>& nums,vector<vector<int>>&ans,vector<int>&allSubsets,int i){
        // base case
        if(i>=nums.size()){
            ans.push_back(allSubsets);
            return;
        }
        // include case
        allSubsets.push_back(nums[i]);
        printAllSubsets(nums,ans,allSubsets,i+1);
        allSubsets.pop_back();
        // exclude case
        printAllSubsets(nums,ans,allSubsets,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>allSubsets;
        int index=0;
        printAllSubsets(nums,ans,allSubsets,index);
        return ans;
    }
};