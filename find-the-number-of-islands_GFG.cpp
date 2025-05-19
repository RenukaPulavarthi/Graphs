//https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1


public:
    void dfs(vector<vector<char>>& grid,vector<vector<int>>&visit,int row,int col){
        if(row>=grid.size() || col>=grid[0].size() || grid[row][col]=='W' || visit[row][col]==1) return;
        int r[]={0,0,1,1,1,-1,-1,-1};
        int c[]={1,-1,-1,0,1,-1,0,1};
        visit[row][col]=1;
        for(int i=0;i<8;i++){
            dfs(grid,visit,row+r[i],col+c[i]);
        }
    }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='L' && visited[i][j]!=1){
                    dfs(grid,visited,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
