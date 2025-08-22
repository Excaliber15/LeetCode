class Solution {
  public:
    void prinAllSubsequneces(string s,vector<string>&ans,int index,string output){
        // base case
        if(index>=s.length()){
            if(output.length()>0){
                ans.push_back(output);
            }
            return;
        }
        char ch=s[index];
        // include ans
        prinAllSubsequneces(s,ans,index+1,output+ch);
        // exclude ans
        prinAllSubsequneces(s,ans,index+1,output);
    }
    vector<string> AllPossibleStrings(string s) {
        // Code here
        vector<string>ans;
        int index=0;
        string output="";
        prinAllSubsequneces(s,ans,index,output);
        // sort  lexographically
        sort(ans.begin(),ans.end());
        return ans;
    }
};