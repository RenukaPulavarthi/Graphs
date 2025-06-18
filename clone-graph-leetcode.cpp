//https://leetcode.com/problems/clone-graph/?envType=problem-list-v2&envId=graph

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        queue<Node*>que;
        map<Node*,Node*>cloned;
        Node* n=new Node(node->val);
        cloned[node]=n;
        que.push(node);
        while(!que.empty()){
            Node* curr=que.front();
            que.pop();
            for(auto it:curr->neighbors){
                if(cloned.find(it)==cloned.end()){
                    cloned[it]=new Node(it->val);
                    que.push(it);
                }
                cloned[curr]->neighbors.push_back(cloned[it]);
            }
        }
        return cloned[node];
    }
};
