//https://leetcode.com/problems/is-graph-bipartite/?envType=problem-list-v2&envId=graph

class Solution {
private:
    bool bfs(vector<vector<int>>&adj,queue<int>&que,int st,vector<int>&visit){
        que.push(st);
        visit[st]=0;
        while(!que.empty()){
            int v=que.front();
            que.pop();
            for(auto it:adj[v]){
                if(visit[it]==-1){
                    visit[it]=(visit[v]==0?1:0);
                    que.push(it);
                }
                else if(visit[it]==visit[v]) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        queue<int>que;
        vector<int>visit(n,-1);
        for(int i=0;i<n;i++){
            if(visit[i]==-1){
                if(!bfs(adj,que,i,visit)) return false;
            }
        }
        return true;
    }
};
