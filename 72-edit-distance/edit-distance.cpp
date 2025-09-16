class Solution {
public:
    int minDistance_solver(string&word1, string&word2,int i,int j,vector<vector<int>>&dp){
        // base cases
        if(i>word1.size()) return j+1;
        if(j>word2.size()) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]) return 0+minDistance_solver(word1,word2,i-1,j-1,dp);
        int insert=1+minDistance_solver(word1,word2,i,j-1,dp);
        int del=1+minDistance_solver(word1,word2,i-1,j,dp);
        int replace=1+minDistance_solver(word1,word2,i-1,j-1,dp);
        int finalAns=min(min(insert,del),replace);
        return dp[i][j]= finalAns;
    }
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        int i=n-1,j=m-1;
        vector<vector<int>>dp(n+1,vector<int>(m,-1));
        int ans=minDistance_solver(word1,word2,i,j,dp);
        return ans;
    }
};