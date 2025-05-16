//https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?page=1&category=Graph&sortBy=submissions

class Solution {
  public:
    void dfs(vector<vector<int>>&adj,vector<int>&visited,int start,bool &ans){
        if(ans==true) return;
        visited[start]=1;
        for(auto i:adj[start]){
            if(visited[i]==0)
                dfs(adj,visited,i,ans);
            else if(visited[i]==1) ans=true;
        }
        visited[start]=2;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
         vector<vector<int>>adj(V);
         for(auto i:edges){
             adj[i[0]].push_back(i[1]);
         }
        vector<int>visited(V,0);
        bool ans=false;
         
         for(int i=0;i<V;i++){
             if(visited[i]==0){
                 dfs(adj,visited,i,ans);
                 if(ans==true) return true;
             }
         }
         return ans;
    }
};
