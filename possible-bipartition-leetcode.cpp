//https://leetcode.com/problems/possible-bipartition/?envType=problem-list-v2&envId=graph

class Solution {
private:
    bool bfs(vector<vector<int>>&adj,vector<int>&visit,queue<int>&que,int st){
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
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);
        for(auto it:dislikes){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>visit(n+1,-1);
        queue<int>que;
        for(int i=1;i<=n;i++){
            if(visit[i]==-1){
                if(!bfs(adj,visit,que,i)) return false;
            }
        }
        return true;
    }
};
