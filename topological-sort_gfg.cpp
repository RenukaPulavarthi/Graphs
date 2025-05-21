//https://www.geeksforgeeks.org/problems/topological-sort/1?page=1&category=Graph&sortBy=submissions

class Solution {
  private:
    void dfs(vector<vector<int>>&adj,vector<int>&visited,stack<int>&st,int start){
        if(visited[start]==1) return;
        visited[start]=1;
        for(auto it:adj[start]){
            if(!visited[it])
                dfs(adj,visited,st,it);
        }
        st.push(start);
        visited[start]=2;
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
        }
        vector<int>visited(V,0);
        stack<int>st;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(adj,visited,st,i);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            // cout<<st.top()<<endl;
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
