class Solution {
  public:
    int search(vector<int>& arr, int x) {
        // Linear Search Algo
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]==x){
                return i; // Element Found
            }
        }
        return -1; // Element Not Found
    }
};