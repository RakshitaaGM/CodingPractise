// Hint : BFS or dFS
class Solution {
public:
    void bfs(int row, int col, vector<vector<char>> grid, vector<vector<bool>>& vis)
    {
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = true;
        vector<int> dr = {1, 0, -1, 0};
        vector<int> dc = {0, -1, 0, 1};
        while(!q.empty())
        {
            auto top = q.front();
            q.pop();
            for(int i = 0; i < 4; i++)
            {
                int r = top.first + dr[i];
                int c = top.second + dc[i];
                if(r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && !vis[r][c] && grid[r][c] == '1')
                {
                    q.push({r, c});
                    vis[r][c] = true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(m,vector<bool>(n, false));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++){
                if(!visited[i][j] && grid[i][j] =='1')
                {
                   count++;
                    bfs(i, j, grid, visited);
                }
            }
        }
        return count;
    }
};