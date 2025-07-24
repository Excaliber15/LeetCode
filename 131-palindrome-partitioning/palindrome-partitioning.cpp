class Solution {
public:
    bool isPalindrome(string s){
        string s2=s;
        reverse(s2.begin(),s2.end());
        return s==s2;
    }
    void solve(string s,vector<vector<string>>&ans,vector<string>&v){
        // base cases
        if(s.size()==0){
            ans.push_back(v);
            return;
        }
        for(int i=0;i<s.size();i++){
            string part=s.substr(0,i+1);
            if(isPalindrome(part)){
                v.push_back(part);
                solve(s.substr(i+1),ans,v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>v;
        solve(s,ans,v);
        return ans;
    }
};