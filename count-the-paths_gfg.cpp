//https://www.geeksforgeeks.org/problems/count-the-paths4332/1

class Solution {
  private:
    int dfs(vector<vector<int>>&adj,vector<int>&visited,int st,int dest,vector<int>&DP){
        if(st==dest) return 1;
        if(DP[st]!=-1) return DP[st];
        visited[st]=1;
        int ans=0;
        for(auto it:adj[st]){
            if(!visited[it]){
                ans+=dfs(adj,visited,it,dest,DP);
            }
        }
        visited[st]=0;
        return DP[st]=ans;
    }
  public:
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        // Code here
        vector<vector<int>>adj(V);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
        }
        vector<int>visited(V,0);
        vector<int>DP(V,-1);
        return dfs(adj,visited,src,dest,DP);
    }
};
