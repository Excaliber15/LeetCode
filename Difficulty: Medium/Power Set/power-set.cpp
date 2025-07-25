class Solution {
  public:
    void printAllSubsequences(string s,vector<string>&ans,string output,int i){
        // base case
        if(i>=s.size()){
            if(output.length()>0){
                ans.push_back(output);
            }
            return;
        }
        char ch=s[i];
        // include ans
        printAllSubsequences(s,ans,output+ch,i+1);
        // exclude ans
        printAllSubsequences(s,ans,output,i+1);
    }
    vector<string> AllPossibleStrings(string s) {
        vector<string>ans;
        string output="";
        int index=0;
        printAllSubsequences(s,ans,output,index);
        sort(ans.begin(),ans.end());
        return ans;
    }
};