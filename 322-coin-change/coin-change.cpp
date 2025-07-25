class Solution {
public:
    int solve(vector<int>& coins, int amount,vector<int>&dp){
        // base case
        if(amount==0) return 0;
        if(amount<0) return INT_MAX;
        if(dp[amount]!=-1) return dp[amount];
        int minCoinAns=INT_MAX;
        for(int i=0;i<coins.size();i++){
            int coin=coins[i];
            if(coin<=amount){
                int recAns=solve(coins,amount-coin,dp);
                if(recAns!=INT_MAX){
                    int minCoinUsed=1+recAns;
                    minCoinAns=min(minCoinAns,minCoinUsed);
                }
            }
        }
        dp[amount]=minCoinAns;
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        // create DP
        vector<int>dp(amount+1,-1);
        int ans=solve(coins,amount,dp);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};