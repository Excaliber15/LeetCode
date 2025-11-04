class Solution {
public:
    void printAllPermutation(vector<int>& nums,vector<vector<int>>&ans,int i){
        // base case
        if(i>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            printAllPermutation(nums,ans,i+1);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int index=0;
        printAllPermutation(nums,ans,index);
        return ans;
    }
};