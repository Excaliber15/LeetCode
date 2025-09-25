class Solution {
  public:
    void printAllSubsetSums(vector<int>& arr,vector<int>&ans,int sum,int i){
        // base case
        if(i>=arr.size()){
            ans.push_back(sum);
            return;
        }
        // include ans
        printAllSubsetSums(arr,ans,sum+arr[i],i+1);
        // exclude ans
        printAllSubsetSums(arr,ans,sum,i+1);
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int>ans;
        int sum=0;
        int index=0;
        printAllSubsetSums(arr,ans,sum,index);
        return ans;
    }
};