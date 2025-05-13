//https://leetcode.com/problems/all-paths-from-source-to-target/?envType=problem-list-v2&envId=graph

class Solution {
public:
    void solve(int idx,vector<vector<int>>&graph,vector<int>visited,vector<int>path,vector<vector<int>>&ans){
        for(auto it:graph[idx]){
            if(visited[it]==1) continue;
            visited[it]=1;
            path.push_back(it);
            if(it==graph.size()-1){
                ans.push_back(path);
            }
            else{
                solve(it,graph,visited,path,ans);
            }
            path.pop_back();
            visited[it]=0;
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>visited(graph.size(),0);
        solve(0,graph,visited,{0},ans);
        return ans;
    }
};
