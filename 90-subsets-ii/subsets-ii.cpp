class Solution {
public:
    void printUniqueSubsets(vector<int>& nums,vector<vector<int>>&ans,vector<int>&v,int i){
        // base cases
        if(i>=nums.size()){
            ans.push_back(v);
            return;
        }
        // include ans
        v.push_back(nums[i]);
        printUniqueSubsets(nums,ans,v,i+1);
        v.pop_back();
        int idx=i+1;
        while(idx<nums.size() && nums[idx]==nums[idx-1]) idx++;
        // exclude ans
        printUniqueSubsets(nums,ans,v,idx);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>v;
        int index=0;
        printUniqueSubsets(nums,ans,v,index);
        return ans;
    }
};