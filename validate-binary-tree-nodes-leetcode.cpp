//https://leetcode.com/problems/validate-binary-tree-nodes/?envType=problem-list-v2&envId=graph

class Solution {
private:
    bool bfs(vector<vector<int>>&adj,vector<int>&visit,queue<int>&que){
        while(!que.empty()){
            int v=que.front();
            // cout<<v<<endl;
            que.pop();
            for(auto it:adj[v]){
                if(visit[it]==1) return false;
                visit[it]=1;
                que.push(it);
            }
        }
        return true;

    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<vector<int>>adj(n);
        set<int>se;
        for(int i=0;i<n;i++){
            if(leftChild[i]!=-1){
                adj[i].push_back(leftChild[i]);
                se.insert(leftChild[i]);
            }
            if(rightChild[i]!=-1){
                adj[i].push_back(rightChild[i]);
                se.insert(rightChild[i]);
            }
        }
        int r;
        for(int i=0;i<n;i++){
            if(se.find(i)==se.end()){
                r=i;
                break;
            }
        }
        vector<int>visit(n,0);
        queue<int>que;
        que.push(r);
        visit[r]=1;
        bool ans=bfs(adj,visit,que);
        for(auto it:visit){
            if(it==0) return false;
        }
        return ans;
    }
};
