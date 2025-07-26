class Solution {
public:
    int solve(string&s,string&a,int i,int j,vector<vector<int>>&dp){
        // base case
        if(i>=s.size() || j>=a.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        // RE
        int ans=0;
        if(s[i]==a[j]){
            ans=1+solve(s,a,i+1,j+1,dp);
        }
        else{
            ans=max(solve(s,a,i+1,j,dp),solve(s,a,i,j+1,dp));
        }
        dp[i][j]=ans;
        return dp[i][j];
    }
    int longestPalindromeSubseq(string s) {
        int i=0;
        int j=0;
        string a=s;
        reverse(a.begin(),a.end());
        vector<vector<int>>dp(s.length()+1,vector<int>(a.length()+1,-1));
        int ans=solve(s,a,i,j,dp);
        return ans;
    }
};