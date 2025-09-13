class Solution {
  public:
    bool f(vector<int>& arr, int sum,int index,vector<vector<int>>&dp){
        // base cases
        if(sum==0) return true;
        if(index==0) return (arr[0]==sum);
        if(dp[sum][index]!=-1) return dp[sum][index];
        bool excludeAns=f(arr,sum,index-1,dp);
        bool includeAns=false;
        if(arr[index]<=sum){
            includeAns=f(arr,sum-arr[index],index-1,dp);
        }
        dp[sum][index]=includeAns | excludeAns;
        return dp[sum][index];
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