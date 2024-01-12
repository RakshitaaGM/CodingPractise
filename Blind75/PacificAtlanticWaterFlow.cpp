// Using BFS or DFS, start from the corners

class Solution {
public:
    void dfs(vector<vector<int>>& h, vector<vector<int>>& vis, int i, int j)
    {
       int m = h.size();
       int n = h[0].size();
        vis[i][j] = 1;
        if(i-1 >=0 && !vis[i-1][j] && h[i-1][j] >= h[i][j])
            dfs(h, vis, i-1, j);
        if(i+1 < m && !vis[i+1][j] && h[i+1][j] >= h[i][j])
            dfs(h, vis, i+1, j);
        if(j-1 >=0 && !vis[i][j-1] && h[i][j-1] >= h[i][j])
            dfs(h, vis, i, j-1);
        if(j+1 < n && !vis[i][j+1] && h[i][j+1] >= h[i][j])
            dfs(h, vis, i, j+1);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> P(m, vector<int>(n));
        vector<vector<int>> A(m, vector<int>(n));
        for(int i = 0; i < m; i++)
        {
            dfs(heights, P, i, 0);
            dfs(heights, A, i, n-1);
        }
        for(int j = 0; j < n; j++)
        {
            dfs(heights, P, 0, j);
            dfs(heights, A, m-1, j);
        }
        vector<vector<int>> res;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(P[i][j] && A[i][j])
                res.push_back(vector<int>{i, j});
            }
        }
        return res;
    }
};