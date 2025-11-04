class Solution {
  public:
    void printAllSubsequences(string&s,vector<string>&ans,string output,int i){
        // base case
        if(i>=s.size()){
            ans.push_back(output);
            return;
        }
        // include case
        printAllSubsequences(s,ans,output+s[i],i+1);
        // exclude case
        printAllSubsequences(s,ans,output,i+1);
    }
    vector<string> AllPossibleStrings(string s) {
        // Code here
        vector<string>ans;
        string output="";
        int index=0;
        printAllSubsequences(s,ans,output,index);
        sort(ans.begin(),ans.end());
        return ans;
    }
};