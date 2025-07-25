class Solution {
public:
    int solve(string&a, string&b,int i,int j,vector<vector<int>>&dp){
        // base case
        if(i>=a.size()) return b.size()-j;
        if(j>=b.size()) return a.size()-i;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(a[i]==b[j]){
            ans=0+solve(a,b,i+1,j+1,dp);
        }
        else{
            int insert=1+solve(a,b,i,j+1,dp);
            int replace=1+solve(a,b,i+1,j+1,dp);
            int remove=1+solve(a,b,i+1,j,dp);
            ans=min(insert,min(replace,remove));
        }
        dp[i][j]=ans;
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.length()+1,vector<int>(word2.length()+1,-1));
        int i=0;
        int j=0;
        int ans=solve(word1,word2,i,j,dp);
        return ans;
    }
};