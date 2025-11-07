class Solution {
  public:
    int search(vector<int>& arr, int x) {
        // code here
        for(int i=0;i<arr.size();i++){
            if(arr[i]==x) return i; // Element Found
        }
        return -1; // Element Not Found
    }
};