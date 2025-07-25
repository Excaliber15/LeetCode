class Solution {
  public:
    void solve(vector<int>& arr,vector<int>&ans,int i,int sum){
        // base case
        if(i>=arr.size()){
            ans.push_back(sum);
            return;
        }
        // include ans
        solve(arr,ans,i+1,sum+arr[i]);
        // exclude ans
        solve(arr,ans,i+1,sum);
    }
    vector<int> subsetSums(vector<int>& arr) {
        vector<int>ans;
        int index=0;
        int sum=0;
        solve(arr,ans,index,sum);
        return ans;
    }
};