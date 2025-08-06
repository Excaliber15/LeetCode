class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>ans(n,0);
        stack<int>s;
        for(int i=0;i<n;i++){
            while(s.size()>0 && arr[s.top()]<=arr[i]){
                s.pop();
            }
            if(s.empty()){
                ans[i]=i+1;
            }
            else{
                ans[i]=i-s.top();
            }
            s.push(i);
        }
        return ans;
    }
};