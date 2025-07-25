class Solution {
public:
    void solve(vector<int>& candidates, int target,vector<vector<int>>&ans,vector<int>&v,int index){
        // base cases
        if(target==0){
            ans.push_back(v);
            return;
        }
        if(target<0) return;
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]) continue; // handling the duplicate values
            v.push_back(candidates[i]);
            solve(candidates,target-candidates[i],ans,v,i+1); // updating the target 
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>v;
        int index=0;
        solve(candidates,target,ans,v,index);
        return ans;
    }
};