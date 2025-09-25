class Solution {
  public:
    void printAllSubsequences(string s,vector<string>&ans,int i,string output){
        // base case
        if(i>=s.size()){
            if(output.length()>0){
                ans.push_back(output);
            }
            return;
        }
        // include case
        printAllSubsequences(s,ans,i+1,output+s[i]);
        // exclude case
        printAllSubsequences(s,ans,i+1,output);
    }
    vector<string> AllPossibleStrings(string s) {
        // Code here
        vector<string>ans;
        int index=0;
        string output="";
        printAllSubsequences(s,ans,index,output);
        sort(ans.begin(),ans.end());
        return ans;
    }
};