// User function Template for C++

class Solution {
  public:
    int rodCutting_helper(vector<int> &price,int n,int i,vector<vector<int>>&dp){
        // base case
        if(i==0) return n*price[0];
        if(dp[n][i]!=-1) return dp[n][i];
        int excludeAns=0+rodCutting_helper(price,n,i-1,dp);
        int includeAns=INT_MIN;
        int rodLength=i+1;
        if(rodLength<=n){
            includeAns=price[i]+rodCutting_helper(price,n-rodLength,i,dp);
        }
        int finalAns=max(includeAns,excludeAns);
        dp[n][i]=finalAns;
        return dp[n][i];
    }
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        int index=n-1;
        vector<vector<int>>dp(n+1,vector<int>(n,-1));
        int ans=rodCutting_helper(price,n,index,dp);
        return ans;
    }
};