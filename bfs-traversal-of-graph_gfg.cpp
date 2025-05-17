//https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1?page=1&category=Graph&sortBy=submissions

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        queue<int>que;
        que.push(0);
        vector<int>visited(adj.size(),0);
        vector<int>ans;
        while(!que.empty()){
            int vertex=que.front();
            if(!visited[vertex]) ans.push_back(vertex);
            visited[vertex]=1;
            
            que.pop();
            for(auto it:adj[vertex]){
                if(!visited[it]){
                    que.push(it);
                }
            }
        }
        return ans;
    }
};
