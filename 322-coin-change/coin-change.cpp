class Solution {
public:
    int coinChange_helper(vector<int>& coins, int amount,int i,vector<vector<int>>&dp){
        // base case
        if(amount==0) return 0;
        if(amount<0) return INT_MAX;
        if(dp[amount][i]!=-1) return dp[amount][i];
        int minCoinAns=INT_MAX;
        for(int i=0;i<coins.size();i++){
            int coin=coins[i];
            if(coin<=amount){
                int recAns=coinChange_helper(coins,amount-coin,i+1,dp);
                if(recAns!=INT_MAX){
                    int minCoinUsed=1+recAns;
                    minCoinAns=min(minCoinAns,minCoinUsed);
                }
            }
        }
        dp[amount][i]=minCoinAns;
        return dp[amount][i];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int index=0;
        vector<vector<int>>dp(amount+1,vector<int>(n+1,-1));
        int ans=coinChange_helper(coins,amount,index,dp);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};