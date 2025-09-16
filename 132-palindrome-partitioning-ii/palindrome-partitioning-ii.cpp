class Solution {
public:
    bool isPalindrome(int i,int j,string&s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int minCut_solver(string&s,int n,int i,vector<int>&dp){
        // base case
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int minCost=INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,s)){
                int cost=1+minCut_solver(s,n,j+1,dp);
                minCost=min(minCost,cost);
            }
        }
        dp[i]=minCost;
        return dp[i];
    }
    int minCut(string s) {
        int n=s.size();
        int index=0;
        vector<int>dp(n+1,-1);
        int ans=minCut_solver(s,n,index,dp)-1;
        return ans;
    }
};