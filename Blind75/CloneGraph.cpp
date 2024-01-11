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
// Using BFS
class Solution {
public:
    unordered_map<Node* , Node*> mp; // declaring map, to check whwther we have a copy of node or not and also to store copy
    
    Node* cloneGraph(Node* node) {
        if(node == NULL) // if node is null, then simply return null
        {
            return NULL;
        }
        
        Node* first = new Node(node -> val, {}); // make a copy of first node
        mp[node] = first;
        
        queue<Node*> q; //For bfs, we create queue
        q.push(node); // push into queue
        
        while(q.empty() == false) // until q. empty == false
        {
            Node* curr = q.front(); // extract front node
            q.pop(); // pop that from queue
            
            for(auto adj: curr -> neighbors) // now travel in adjcant
            {
                if(mp.find(adj) == mp.end()) // if not present in map
                {
                    mp[adj] = new Node(adj -> val, {}); // then create copy
                    q.push(adj); // push nto the queue
                    
                }
                
                mp[curr] -> neighbors.push_back(mp[adj]); // in current node push adjcant node
            }
        }
        
        return mp[node];
    }
};