class Solution {
public:
    int rob_helper(vector<int>& nums,int i,vector<int>&dp){
        // base case
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int includeAns=nums[i]+rob_helper(nums,i+2,dp);
        int excludeAns=0+rob_helper(nums,i+1,dp);
        int finalAns=max(includeAns,excludeAns);
        dp[i]=finalAns;
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        int index=0;
        vector<int>dp(n+2,-1);
        int ans=rob_helper(nums,index,dp);
        return ans;
    }
};