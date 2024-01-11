// Use DFS and hashmap to keep track of visited nodes
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
    Node* dfs(Node* node, map<Node*, Node*>& mp)
    {
        vector<Node*> neighbor;
        Node* clone = new Node(node->val);
        mp[node] = clone;
        for(auto n : node->neighbors)
        {
            if(mp.find(n) != mp.end())
            {
                neighbor.push_back(mp[n]);
            }
            else
            {
                neighbor.push_back(dfs(n, mp));
            }
        }
        clone->neighbors = neighbor;
        return clone;
    }

    Node* cloneGraph(Node* node) {
        if(node == NULL)
        {
            return NULL;
        }
        if(node->neighbors.size() == 0)
        {
            Node* clone = new Node(node->val);
            return clone;
        }
        map<Node*, Node*> mp;
        return dfs(node, mp);
        
    }
};