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
    int f(string&s,int n,int i,vector<int>&dp){
        // base case
        if(i==n) return 0;
        int minAns=INT_MAX;
        if(dp[i]!=-1) return dp[i];
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,s)){
                int ans=1+f(s,n,j+1,dp);
                minAns=min(minAns,ans);
            }
        } 
        return dp[i]=minAns;
    }
    int minCut(string s) {
        int n=s.size();
        int index=0;
        vector<int>dp(n+1,-1);
        int ans=f(s,n,index,dp)-1;
        return ans;
    }
};