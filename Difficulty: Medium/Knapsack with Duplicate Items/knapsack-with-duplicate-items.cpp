// User function Template for C++

class Solution {
  public:
    int knapSack_helper(vector<int>& val, vector<int>& wt, int capacity,int index,vector<vector<int>>&dp){
        // base case
        if(index==0) return (capacity/wt[0])*val[0];
        if(dp[capacity][index]!=-1) return dp[capacity][index];
        int excludeAns=0+knapSack_helper(val,wt,capacity,index-1,dp);
        int includeAns=0;
        if(wt[index]<=capacity){
            includeAns=val[index]+knapSack_helper(val,wt,capacity-wt[index],index,dp);
        }
        int finalAns=max(includeAns,excludeAns);
        dp[capacity][index]=finalAns;
        return dp[capacity][index];
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        int index=n-1;
        vector<vector<int>>dp(capacity+1,vector<int>(n,-1));
        int ans=knapSack_helper(val,wt,capacity,index,dp);
        return ans;
    }
};