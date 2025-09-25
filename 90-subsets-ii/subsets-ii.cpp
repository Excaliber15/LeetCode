class Solution {
public:
    void printAllSubsets(vector<int>& nums,vector<vector<int>>&ans,vector<int>&allSubsets,int i){
        // base case
        if(i>=nums.size()){
            ans.push_back(allSubsets);
            return;
        }
        // include ans
        allSubsets.push_back(nums[i]);
        printAllSubsets(nums,ans,allSubsets,i+1);
        allSubsets.pop_back();
        // exclude ans
        // look for repeatation
        int idx=i+1;
        while(idx<nums.size() && nums[idx]==nums[idx-1]) idx++;
        printAllSubsets(nums,ans,allSubsets,idx);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>allSubsets;
        int index=0;
        printAllSubsets(nums,ans,allSubsets,index);
        return ans;
    }
};