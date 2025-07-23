class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>>&ans,vector<int>&v,int i){
        // base case
        if(i>=nums.size()){
            ans.push_back(v);
            return;
        }
        // include ans
        v.push_back(nums[i]);
        solve(nums,ans,v,i+1);
        v.pop_back();
        // exclude ans
        int idx=i+1;
        while(idx<nums.size() && nums[idx]==nums[idx-1]){
            idx++;
        }
        solve(nums,ans,v,idx);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>v;
        int index=0;
        solve(nums,ans,v,index);
        return ans;
    }
};