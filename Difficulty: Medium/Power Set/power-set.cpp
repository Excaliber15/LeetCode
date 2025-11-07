class Solution {
  public:
    void printAllSubsequneces(string s, vector<string>&ans,int i,string output){
        // base case
        if(i>=s.size()){
            ans.push_back(output);
            return;
        }
        // include ans
        printAllSubsequneces(s,ans,i+1,output+s[i]);
        // exclude ans
        printAllSubsequneces(s,ans,i+1,output);
    }
    vector<string> AllPossibleStrings(string s) {
        // Code here
        vector<string>ans;
        int index=0;
        string output="";
        printAllSubsequneces(s,ans,index,output);
        sort(ans.begin(),ans.end());
        return ans;
    }
};