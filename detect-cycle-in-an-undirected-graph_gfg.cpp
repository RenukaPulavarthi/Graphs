//https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

class Solution {
  public:
   bool cycle(int start,vector<vector<int>>&adj,vector<int>&visit){
       queue<pair<int,int>>q;
        q.push({start,-1});
        visit[start]=1;
        while(!q.empty()){
            int vertex=q.front().first;
            int prev=q.front().second;
            q.pop();
            for(auto it:adj[vertex]){
                if(!visit[it]){
                    visit[it]=1;
                    q.push({it,vertex});
                }
                else if(it!=prev) return true;
            }
        }
        return false;
   }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>visit(V,0);
        for(int i=0;i<V;i++){
            if(!visit[i]){
                if(cycle(i,adj,visit)) return true;
            }
        }
        
        return false;
    }
};
