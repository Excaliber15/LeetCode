// User function Template for C++

class Solution {
  public:
    int rodCutting_helper(vector<int> &price,int n,int index,vector<vector<int>>&dp){
        // base case
        if(index==0) return n*price[0];
        if(dp[n][index]!=-1) return dp[n][index];
        int excludeAns=0+rodCutting_helper(price,n,index-1,dp);
        int includeAns=INT_MIN;
        int rodLength=index+1;
        if(rodLength<=n){
            includeAns=price[index]+rodCutting_helper(price,n-rodLength,index,dp);
        }
        int finalAns=max(includeAns,excludeAns);
        dp[n][index]=finalAns;
        return dp[n][index];
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