class Solution {
public:
    void combinationSum2_helper(vector<int>& candidates, int target,vector<vector<int>>&ans,vector<int>&v,int index){
        // base case
        if(target==0){
            ans.push_back(v);
            return;
        }
        if(target<0) return;

        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]) continue;
            v.push_back(candidates[i]);
            combinationSum2_helper(candidates,target-candidates[i],ans,v,i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>v;
        int index=0;
        combinationSum2_helper(candidates,target,ans,v,index);
        return ans;
    }
};