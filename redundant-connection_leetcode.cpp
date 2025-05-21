//https://leetcode.com/problems/redundant-connection/?envType=problem-list-v2&envId=graph

class Solution {
private:
    bool dfs(map<int,vector<int>>&mp,vector<int>&visited,int start,int parent){
        visited[start]=1;
        for(auto it:mp[start]){
            if(visited[it]==0){
               if(dfs(mp,visited,it,start)) return true;
            }
            else if(it!=parent){
                return true;
            }
        } 
        visited[start]=2;
        return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        map<int,vector<int>>adj;
        int n=0;
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            n=max(n,max(it[0],it[1]));
            vector<int>visited(n+1,0);
            
            if(dfs(adj,visited,it[0],-1)) return it;
        }
        return {};
    }
};
