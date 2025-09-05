class Solution {
public:
    int coinChange_helper(int amount, vector<int>& coins,int i,vector<vector<int>>&dp){
        // basec case
        if(i==0) return (amount % coins[0]==0);
        if(dp[amount][i]!=-1) return dp[amount][i];
        int excludeAns=coinChange_helper(amount,coins,i-1,dp);
        int includeAns=0;
        if(coins[i]<=amount){
            includeAns=coinChange_helper(amount-coins[i],coins,i,dp);
        }
        int finalAns=includeAns+excludeAns;
        dp[amount][i]=finalAns;
        return dp[amount][i];
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        int index=n-1;
        vector<vector<int>>dp(amount+1,vector<int>(n,-1));
        return coinChange_helper(amount,coins,index,dp);
    }
};