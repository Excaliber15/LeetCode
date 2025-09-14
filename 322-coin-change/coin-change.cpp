class Solution {
public:
    int coinChange_solver(vector<int>& coins, int amount,int i,vector<int>&dp){
        // base case
        if(amount==0) return 0;
        if(amount<0) return INT_MAX;
        if(dp[amount]!=-1) return dp[amount];
        int minCoinAns=INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(coins[i]<=amount){
                int recAns=coinChange_solver(coins,amount-coins[i],i+1,dp);
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
        int n=coins.size();
        int index=0;
        vector<int>dp(amount+1,-1);
        int ans=coinChange_solver(coins,amount,index,dp);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};