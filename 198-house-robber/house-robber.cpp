class Solution {
public:
    int solve(vector<int>& nums,int i,vector<int>&dp){
        // base case
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        // RE
        int includeAns=nums[i]+solve(nums,i+2,dp);
        int excludeAns=0+solve(nums,i+1,dp);
        int finalAns=max(includeAns,excludeAns);
        dp[i]=finalAns;
        return dp[i];
    }
    int rob(vector<int>& nums) {
        // create dp array
        int n=nums.size();
        vector<int>dp(n+1,-1);
        int index=0;
        int ans=solve(nums,index,dp);
        return ans;
    }
};