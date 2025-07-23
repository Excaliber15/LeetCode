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
        //exclude ans
        solve(nums,ans,v,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        int index=0;
        solve(nums,ans,v,index);
        return ans;
    }
};