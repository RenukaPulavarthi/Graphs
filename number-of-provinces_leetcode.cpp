//https://leetcode.com/problems/number-of-provinces/?envType=problem-list-v2&envId=graph

class Solution {
private:
    void dfs(vector<vector<int>>&adj,vector<int>&visit,int start){
        visit[start]=1;
        for(int i=0;i<adj.size();i++){
            if(i!=start){
                if(adj[start][i]==1 && !visit[i]){
                    dfs(adj,visit,i);
                }
            }
        }
        visit[start]=2;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>visit(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!visit[i]){
                dfs(isConnected,visit,i);
                // for(auto it:visit) cout<<it<<endl;
                ans++;
            }
        }
        return ans;
    }
};
