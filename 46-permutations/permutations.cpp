class Solution {
public:
    void printAllPermutations(vector<int>& nums,vector<vector<int>>&ans,int i){
        // base case
        if(i>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            printAllPermutations(nums,ans,i+1);
            swap(nums[i],nums[j]); // back tracking
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int index=0;
        printAllPermutations(nums,ans,index);
        return ans;
    }
};