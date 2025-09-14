class Solution {
public:
    int coinChange_helper(int amount, vector<int>& coins,int index,vector<vector<int>>&dp){
        // base cases
        if(index==0) return (amount%coins[0]==0);
        if(dp[amount][index]!=-1) return dp[amount][index];
        // exclude ans
        int excludeAns=coinChange_helper(amount,coins,index-1,dp);
        // include ans
        int includeAns=0;
        if(coins[index]<=amount){
            includeAns=coinChange_helper(amount-coins[index],coins,index,dp);
        }
        return dp[amount][index]=includeAns+excludeAns;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        int index=n-1;
        vector<vector<int>>dp(amount+1,vector<int>(n,-1));
        int ans=coinChange_helper(amount,coins,index,dp);
        return ans;
    }
};