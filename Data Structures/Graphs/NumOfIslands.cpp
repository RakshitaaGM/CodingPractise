//Source : https://leetcode.com/problems/number-of-islands/
//Author : Rakshitaa Geetha Mohan
//email ID : rakshitaagm@gmail.com
//Date : 09/17/2022
//Difficulty level : Medium
///////////////////////////////////////////////////////////////////
// Given an m x n 2D binary grid grid which represents a map of '1's (land) 
// and '0's (water), return the number of islands.
// An island is surrounded by water and is formed by connecting adjacent 
// lands horizontally or vertically. You may assume all four edges of the grid 
// are all surrounded by water.
// Example 1:
// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// Example 2:
// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3
///////////////////////////////////////////////////////////////////
// Solution : BFS
// Sol complexity :
// Time : O(mn)
// Space : O(mn)
///////////////////////////////////////////////////////////////////
class Solution {
public:
    void bfs(int r, int c, vector<vector<bool>>& vis, vector<vector<char>> grid)
    {
        int dr[] = {1, 0, -1, 0};
        int dc[] = {0, -1, 0, 1};
        queue<pair<int, int>> q;
        q.push(make_pair(r, c));
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(uint i = 0; i < 4; i++)
            {
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                
                if(nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() && grid[nrow][ncol] == '1' && !vis[nrow][ncol])
                {
                    
                    vis[nrow][ncol] = true;
                    q.push(make_pair(nrow, ncol));
                }
            }
        }
    }
      
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;
        vector<vector<bool>> vis(n, vector<bool> (m,false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    count++;
                     vis[i][j] = true;
                    bfs(i, j, vis, grid);
                   
                }
            }
        }
        return count;
        
    }
};
///////////////////////////////////////////////////////////////////
// Solution : DFS
// Sol complexity :
// Time : O(mn)
// Space : O(mn)
///////////////////////////////////////////////////////////////////
void dfs(int r, int c, vector<vector<bool>>& vis, vector<vector<char>>& grid)
    {
       int dr[] = {1, 0 ,-1, 0};
       int dc[] = {0, -1, 0, 1};
       for(int i = 0; i < 4; i++)
       {
           int row = r + dr[i];
           int col = c + dc[i];
           if(row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && grid[row][col] == '1' && !vis[row][col])
           {
               vis[row][col] = true;
               dfs(row, col, vis, grid);
           }
       }
    }