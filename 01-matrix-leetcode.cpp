//   https://leetcode.com/problems/01-matrix/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dist(n,vector<int>(m));
        queue<vector<int>>que;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    dist[i][j]=0;
                    que.push({i,j});
                }
                else{
                    dist[i][j]=INT_MAX;
                }
            }
        }
        int row[]={0,0,-1,1};
        int col[]={1,-1,0,0};
        while(!que.empty()){
           int r=que.front()[0];
            int c=que.front()[1];
           que.pop();
           for(int i=0;i<4;i++){
                int nr=r+row[i];
                int nc=c+col[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    if(dist[nr][nc]>dist[r][c]+1){
                        dist[nr][nc]=dist[r][c]+1;
                        que.push({nr,nc});
                    }
                }
           }
        }
        return dist;
    }
};
