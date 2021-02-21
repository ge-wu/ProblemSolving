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
        if (!node) {
            return NULL;
        }
        unordered_map<Node*, Node*> visited;
        queue<Node*> q;
        Node* temp = new Node(node->val, {});
        
        visited[node] = temp;
        q.push(node);
        
        while (!q.empty()) {
            Node* curNode = q.front();
            q.pop();
            for (Node* nei: curNode->neighbors) {
                if (visited.find(nei) == visited.end()) {
                    visited[nei] = new Node(nei->val, {});
                    q.push(nei);
                }
                visited[curNode]->neighbors.push_back(visited[nei]);
            }
        }
        return temp;
    }
};
