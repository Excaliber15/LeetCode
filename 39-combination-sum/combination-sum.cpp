class Solution {
public:
    void combinationSum_helper(vector<int>& candidates, int target,vector<vector<int>>&ans,vector<int>&v,int index){
        // base cases
        if(target==0){
            ans.push_back(v);
            return;
        }
        if(target<0) return;

        for(int i=index;i<candidates.size();i++){
            v.push_back(candidates[i]);
            combinationSum_helper(candidates,target-candidates[i],ans,v,i);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        int index=0;
        combinationSum_helper(candidates,target,ans,v,index);
        return ans;
    }
};