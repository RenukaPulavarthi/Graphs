//https://www.geeksforgeeks.org/problems/rotten-oranges2536/1

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        int n=mat.size(),m=mat[0].size();
        //{{row,col},time}
        queue<pair<pair<int,int>,int>>q;
        int visit[n][m]={0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                visit[i][j]=0;
                if(mat[i][j]==2){
                    visit[i][j]=2;
                    q.push({{i,j},0});
                    
                }
            }
        }
        int col[4]={0,0,-1,1};
        int row[4]={1,-1,0,0};
        int ans=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            ans=max(ans,t);
            q.pop();
            for(int i=0;i<4;i++){
                // cout<<r+row[i]<<" "<<c+col[i]<<" "<<visit[r+row[i]][c+col[i]]<<endl;
                if(0<=r+row[i] && row[i]+r<n && 0<=c+col[i] && c+col[i]<m && mat[r+row[i]][c+col[i]]==1 && visit[r+row[i]][c+col[i]]==0){
                    q.push({{r+row[i],c+col[i]},t+1});
                    visit[r+row[i]][c+col[i]]=2;
                    
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visit[i][j]==0 && mat[i][j]==1) {
                    // cout<<i<<" "<<j<<endl;
                    return -1;
                    
                }
            }
        }
        return ans;
    }
};
