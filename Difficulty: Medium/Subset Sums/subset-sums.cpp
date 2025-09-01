class Solution {
  public:
    void printAllSubsetsSums(vector<int>& arr,vector<int>&ans,int i,int sum){
        // base case
        if(i>=arr.size()){
            ans.push_back(sum);
            return;
        }
        // include ans
        printAllSubsetsSums(arr,ans,i+1,sum+arr[i]);
        // exclude ans
        printAllSubsetsSums(arr,ans,i+1,sum);
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int>ans;
        int index=0;
        int sum=0;
        printAllSubsetsSums(arr,ans,index,sum);
        return ans;
    }
};