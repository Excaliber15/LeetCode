class Solution {
  public:
    int solve(vector<int> &arr,int i,int j,vector<vector<int>>&dp){
        // base case
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int minAns=1e9;
        for(int k=i;k<j;k++){
            int steps=arr[i-1]*arr[k]*arr[j]+solve(arr,i,k,dp)+solve(arr,k+1,j,dp);
            minAns=min(minAns,steps);
        }
        dp[i][j]=minAns;
        return dp[i][j];
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans=solve(arr,1,n-1,dp);
        return ans;
    }
};