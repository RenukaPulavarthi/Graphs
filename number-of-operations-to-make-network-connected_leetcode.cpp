//https://leetcode.com/problems/number-of-operations-to-make-network-connected/?envType=problem-list-v2&envId=graph

class Solution {
public:
    void bfs(vector<vector<int>>&adj,vector<int>&visited,int start){
        visited[start]=1;
        for(auto it:adj[start]){
              if(!visited[it])
                bfs(adj,visited,it);
            }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        vector<int>visited(n,0);
        int ans=-1;
        vector<vector<int>>adj(n);
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        for(int i=0;i<visited.size();i++){
            if(!visited[i]){
                bfs(adj,visited,i);
                ans++;
            }
        }
        return ans;
    }
};
