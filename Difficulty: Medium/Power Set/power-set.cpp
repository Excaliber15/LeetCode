class Solution {
  public:
    
    void solve(string s,vector<string>&ans,int i,string output){
        // base case
        if(i>=s.size()){
            if(output.length()>0){
                ans.push_back(output);
            }
            return;
        }
        char ch=s[i];
        // include ans
        solve(s,ans,i+1,output+ch);
        // exclude ans
        solve(s,ans,i+1,output);
    }
    vector<string> AllPossibleStrings(string s) {
        // Code here
        vector<string>ans;
        int index=0;
        string output="";
        solve(s,ans,index,output);
        // sort lexographically
        sort(ans.begin(),ans.end());
        return ans;
    }
};