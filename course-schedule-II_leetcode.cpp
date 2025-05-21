//https://leetcode.com/problems/course-schedule-ii/?envType=problem-list-v2&envId=graph

class Solution {
private:
    void dfs(vector<vector<int>>&adj,vector<int>&visited,stack<int>&st,int start,bool &cycle){
        visited[start]=1;
        for(auto it:adj[start]){
            if(!visited[it]){
                dfs(adj,visited,st,it,cycle);
                if(cycle==true){
                    return;
                }
            }
            else if(visited[it]==1){
                cycle=true;
                return;
            }
        }
        visited[start]=2;
        st.push(start);
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int>visited(numCourses);
        stack<int>st;
        bool cycle=false;
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                dfs(adj,visited,st,i,cycle);
                if(cycle==true) return {};
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
