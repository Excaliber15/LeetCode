class Solution {
public:
    bool solve(vector<vector<int>>& grid,int n,int r,int c,int expVal){
        // invalid moves
        if(r<0 || c<0 || r>=n || c>=n || grid[r][c]!=expVal){
            return false;
        }
        // valid moves
        if(expVal==n*n-1){
            return true;
        }
        int ans1=solve(grid,n,r-2,c+1,expVal+1);
        int ans2=solve(grid,n,r-1,c+2,expVal+1);
        int ans3=solve(grid,n,r+2,c+1,expVal+1);
        int ans4=solve(grid,n,r+1,c+2,expVal+1);
        int ans5=solve(grid,n,r+2,c-1,expVal+1);
        int ans6=solve(grid,n,r+1,c-2,expVal+1);
        int ans7=solve(grid,n,r-1,c-2,expVal+1);
        int ans8=solve(grid,n,r-2,c-1,expVal+1);

        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        return solve(grid,grid.size(),0,0,0);
    }
};