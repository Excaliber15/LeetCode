class Solution {
  public:
    bool isSafe(int new_x,int new_y,vector<vector<int>>& maze,int n,vector<vector<bool>>&visited){
        if(new_x<0 || new_y<0 || new_x>=n || new_y>=n){
            // out of bound
            return false;
        }
        if(visited[new_x][new_y]==true){
            return false; // already visited
        }
        if(maze[new_x][new_y]==0){
            return false; // blocked space
        }
        return true; // valid positions
    }
    void solve(vector<vector<int>>& maze,int n,vector<vector<bool>>&visited,vector<string>&ans,int src_x,int src_y,int dest_x,int dest_y,string output){
        // base case
        if(src_x==dest_x && src_y==dest_y){
            ans.push_back(output);
            return;
        }
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        char move[]={'U','D','L','R'};
        for(int i=0;i<4;i++){
            int new_x=src_x+dx[i];
            int new_y=src_y+dy[i];
            char movement=move[i];
            if(isSafe(new_x,new_y,maze,n,visited)){
                visited[new_x][new_y]=true;
                output.push_back(movement);
                solve(maze,n,visited,ans,new_x,new_y,dest_x,dest_y,output);
                output.pop_back();
                visited[new_x][new_y]=false;
            }
        }
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n=maze.size();
        vector<string>ans;
        vector<vector<bool>>visited(n,vector<bool>(n,0));
        int src_x=0;
        int src_y=0;
        visited[0][0]=true;
        int dest_x=n-1;
        int dest_y=n-1;
        string output="";
        if(maze[0][0]=0){
            return ans;
        }
        solve(maze,n,visited,ans,src_x,src_y,dest_x,dest_y,output);
        sort(ans.begin(),ans.end());
        return ans;
    }
};