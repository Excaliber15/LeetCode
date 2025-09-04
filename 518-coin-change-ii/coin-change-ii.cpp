class Solution {
public:
    int coinChange_Solver(int amount, vector<int>& coins,int n,int index,vector<vector<int>>&dp){
        // base case
        if(index==0){
            return (amount % coins[0]==0);
        }
        if(dp[amount][index]!=-1) return dp[amount][index];
        int excludeAns=0+coinChange_Solver(amount,coins,n,index-1,dp);
        int includeAns=0;
        if(coins[index]<=amount){
            includeAns=coinChange_Solver(amount-coins[index],coins,n,index,dp);
        }
        int finalAns=includeAns+excludeAns;
        dp[amount][index]=finalAns;
        return dp[amount][index];
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        int index=n-1;
        vector<vector<int>>dp(amount+1,vector<int>(n,-1));
        int ans=coinChange_Solver(amount,coins,n,index,dp);
        return ans;
    }
};