//https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

class Solution {
  private:
    void bfs(vector<vector<int>>&adj,vector<int>&vis,queue<pair<int,int>>&que){
        while(!que.empty()){
            int y=que.front().first;
            int z=que.front().second;
            // cout<<y<<" "<<z<<endl;
            // vis[que.front().first]=que.front().second;
            que.pop();
            for(auto it:adj[y]){
                if(vis[it]==-1){
                    vis[it]=z+1;
                    que.push({it,z+1});
                }
            }
        }
    }
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        vector<int>ans(adj.size(),-1);
        queue<pair<int,int>>que;
        que.push({src,0});
        ans[src]=0;
        bfs(adj,ans,que);
        return ans;
    }
};
