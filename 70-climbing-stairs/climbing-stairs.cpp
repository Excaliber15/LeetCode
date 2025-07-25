class Solution {
public:
    int solve(int n,vector<int>&dp){
        // base case
        if(n==0 || n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        dp[n]=solve(n-1,dp)+solve(n-2,dp);
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        int ans=solve(n,dp);
        return ans;
    }
};