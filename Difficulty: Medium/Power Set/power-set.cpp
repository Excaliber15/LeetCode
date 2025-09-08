class Solution {
  public:
    void printAllSubsequences(string s,vector<string>&ans,int i,string output){
        // base cases
        if(i>=s.size()){
            if(output.length()>0){
                ans.push_back(output);
            }
            return;
        }
        char ch=s[i];
        // include ans
        printAllSubsequences(s,ans,i+1,output+ch);
        // exclude ans
        printAllSubsequences(s,ans,i+1,output);
    }
    vector<string> AllPossibleStrings(string s) {
        // Code here
        vector<string>ans;
        int index=0;
        string output="";
        printAllSubsequences(s,ans,index,output);
        sort(ans.begin(),ans.end()); // sorted lexographically
        return ans;
    }
};