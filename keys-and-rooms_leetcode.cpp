//https://leetcode.com/problems/keys-and-rooms/?envType=problem-list-v2&envId=graph

class Solution {
public:
    void solve(vector<vector<int>>&rooms,vector<int>&visited,int idx){
        if(visited[idx]==1) return;
        visited[idx]=1;
        for(auto it:rooms[idx]){
            solve(rooms,visited,it);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int>visited(rooms.size(),0);
        solve(rooms,visited,0);
        for(auto it:visited){
            // cout<<it<<endl;
            if(it==0) return false;
        }
        return true;

    }
};
