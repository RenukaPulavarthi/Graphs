//https://leetcode.com/problems/course-schedule/?envType=problem-list-v2&envId=graph

class Solution {
private:
    void dfs(vector<vector<int>>&adj,vector<int>&visited,bool &ans,int start){
        if(ans==true) return;
        visited[start]=1;
        for(auto it:adj[start]){
            if(!visited[it]){
                dfs(adj,visited,ans,it);
                if(ans==true) return;
            }
            else if(visited[it]==1){
                ans=true;
                return;
            }
        }
        visited[start]=2;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        bool ans=false;
        vector<int>visited(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                dfs(adj,visited,ans,i);
                if(ans==true) return false;
            }
        }
        return true;
    }
