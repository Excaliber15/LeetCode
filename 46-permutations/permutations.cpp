class Solution {
public:
    void printAllpermutations(vector<int>& nums,vector<vector<int>>&ans,vector<int>&v,int i){
        if(i>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            printAllpermutations(nums,ans,v,i+1);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        int index=0;
        printAllpermutations(nums,ans,v,index);
        return ans;
    }
};