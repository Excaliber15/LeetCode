class Solution {
  public:
    void printAllPermutations(string&s,vector<string>&ans,int i){
        // base case
        if(i>=s.size()){
            ans.push_back(s);
            return;
        }
        for(int j=i;j<s.length();j++){
            swap(s[i],s[j]);
            printAllPermutations(s,ans,i+1);
            swap(s[i],s[j]);
        }
    }
    vector<string> findPermutation(string &s) {
        // Code here there
        vector<string>ans;
        int index=0;
        printAllPermutations(s,ans,index);
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end()); // ✅ remove duplicates
        return ans;
    }
};
