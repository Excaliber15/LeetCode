class Solution {
  public:
    bool f(vector<int>& arr, int sum,int i,vector<vector<int>>&dp){
        // base cases
        if(sum==0) return true;
        if(i==0) return (arr[0]==sum);
        if(dp[sum][i]!=-1) return dp[sum][i];
        bool excludeAns=f(arr,sum,i-1,dp);
        bool includeAns=false;
        if(arr[i]<=sum){
            includeAns=f(arr,sum-arr[i],i-1,dp);
        }
        return dp[sum][i]= includeAns | excludeAns;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        int index=n-1;
        vector<vector<int>>dp(sum+1,vector<int>(n,-1));
        bool ans=f(arr,sum,index,dp);
        return ans;
    }
};