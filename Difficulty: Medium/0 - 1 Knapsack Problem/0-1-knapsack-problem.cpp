class Solution {
  public:
    int knapSack_solver(int capacity, vector<int> &val, vector<int> &wt,int index,vector<vector<int>>&dp){
        // base case
        if(index==0){
            if(wt[0]<=capacity){
                return val[0];
            }
            else{
                return 0;
            }
        }
        if(dp[capacity][index]!=-1) return dp[capacity][index];
        int excludeAns=0+knapSack_solver(capacity,val,wt,index-1,dp);
        int includeAns=0;
        if(wt[index]<=capacity){
            includeAns=val[index]+knapSack_solver(capacity-wt[index],val,wt,index-1,dp);
        }
        int finalAns=max(includeAns,excludeAns);
        dp[capacity][index]=finalAns;
        return dp[capacity][index];
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        int capacity=W;
        int index=n-1;
        vector<vector<int>>dp(capacity+1,vector<int>(n,-1));
        int ans=knapSack_solver(capacity,val,wt,index,dp);
        return ans;
    }
};