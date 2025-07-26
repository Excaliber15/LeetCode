class Solution {
public:
    int solve(vector<int>& cost,int n,vector<int>&dp){
        // base case
        if(n==0 || n==1) return cost[n];
        if(dp[n]!=-1) return dp[n];
        //RE
        dp[n]=cost[n]+min(solve(cost,n-1,dp),solve(cost,n-2,dp));
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        int ans=min(solve(cost,n-1,dp),solve(cost,n-2,dp));
        return ans;
    }
};