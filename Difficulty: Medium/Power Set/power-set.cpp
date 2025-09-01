class Solution {
  public:
    void printAllPermutations(string s,vector<string>&ans,int i,string output){
        // base case
        if(i>=s.size()){
            if(output.length()>0){
                ans.push_back(output);
            }
            return;
        }
        char ch=s[i];
        // include ans
        printAllPermutations(s,ans,i+1,output+ch);
        // exclude ans
        printAllPermutations(s,ans,i+1,output);
    }
    vector<string> AllPossibleStrings(string s) {
        // Code here
        vector<string>ans;
        int index=0;
        string output="";
        printAllPermutations(s,ans,index,output);
        // sort in lexographically order
        sort(ans.begin(),ans.end());
        return ans;
    }
};