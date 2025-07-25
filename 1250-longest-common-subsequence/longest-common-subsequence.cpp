class Solution {
public:
    int solve(string&a, string&b,int i,int j,vector<vector<int>>&dp){
        // base cases
        if(i>=a.size() || j>=b.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        // RE
        int ans=0;
        if(a[i]==b[j]){
            ans=1+solve(a,b,i+1,j+1,dp);
        }
        else{
            ans=max(solve(a,b,i,j+1,dp),solve(a,b,i+1,j,dp));
        }
        dp[i][j]=ans;
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        // Create dp array
        vector<vector<int>>dp(text1.length(),vector<int>(text2.length()+1,-1));
        int i=0;
        int j=0;
        int ans=solve(text1,text2,i,j,dp);
        return ans;
    }
};