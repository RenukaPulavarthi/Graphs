//https://leetcode.com/problems/find-if-path-exists-in-graph/?envType=problem-list-v2&envId=graph

class Solution {
public:
    void dfs(vector<vector<int>>&adj,vector<int>&visited,int source,int &destination,bool &ans){
        if(source==destination || visited[source]==1) {
            ans=true;
            return;
        }
        if(ans==true){
            return;
        }
        visited[source]=1;
        for(auto it:adj[source]){
            if(!visited[it]){
                dfs(adj,visited,it,destination,ans);
            }
        }
        // visited[source]=0;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>visited(n,0);
        bool ans=false;
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(adj,visited,source,destination,ans);
        return ans;
        
    }
};
