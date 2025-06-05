//https://leetcode.com/problems/lexicographically-smallest-equivalent-string/?envType=daily-question&envId=2025-06-05

class Solution {
private:
    void dfs( map<char,vector<int>>&adj,char start,vector<char>&curr,char &sm,vector<int>&visited){
        visited[start-'a']=1;
        sm=min(sm,start);
        curr.push_back(start);
        for(auto it:adj[start]){
            if(!visited[it-'a']){
                dfs(adj,it,curr,sm,visited);
            }
        }
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        map<char,vector<int>>adj;
        for(int i=0;i<s1.size();i++){
            adj[s1[i]].push_back(s2[i]);
            adj[s2[i]].push_back(s1[i]);
        }
        vector<int>visited(26,0);
        map<char,char>mp;
        for(int i=0;i<26;i++){
            cout<<i<<endl;
            char it=i+'a';
            if(visited[i]==0 && adj[it].size()!=0){
                vector<char>curr;
                char sm=it;
                dfs(adj,it,curr,sm,visited);
                cout<<sm<<endl;
                for(auto it:curr){
                    mp[it]=sm;
                }
            }
        }
        string ans="";
        for(auto it:baseStr){
            if(mp.find(it)!=mp.end()) ans+=mp[it];
            else ans+=it;
        }
        return ans;
    }
};
