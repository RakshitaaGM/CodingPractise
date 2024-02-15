class Solution {
public:
    bool dfs(map<int, vector<int>>& adj, vector<int>& vis, int& c)
    {
        if(adj[c].empty())
            return true;
        if(find(vis.begin(), vis.end(), c) != vis.end())
            return false;
        vis.emplace_back(c);
        for(auto a : adj[c])
        {
            if(!dfs(adj, vis, a))
                return false;
        }
        vis.erase(find(vis.begin(), vis.end(), c));
        adj[c].clear();
        return true;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> adj;
        vector<int> vis;
        for(auto c : prerequisites)
        {
            adj[c[0]].emplace_back(c[1]);
        }
        for(int i = 0; i < numCourses; i++)
        {
            if(!dfs(adj, vis, i))
                return false;
        }
        return true;
    }
};