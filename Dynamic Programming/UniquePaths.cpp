//Source : https://leetcode.com/problems/unique-paths/
//Author : Rakshitaa Geetha Mohan
//email ID : rakshitaagm@gmail.com
//Date : 09/19/2022
//Difficulty level : medium
///////////////////////////////////////////////////////////////////
// There is a robot on an m x n grid. The robot is initially located at 
// the top-left corner (i.e., grid[0][0]). The robot tries to move to 
// the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can 
// only move either down or right at any point in time.
// Given the two integers m and n, return the number of possible 
// unique paths that the robot can take to reach the bottom-right corner.
// The test cases are generated so that the answer will be less than or 
// equal to 2 * 109.
// Example
// Input: m = 3, n = 7
// Output: 28
///////////////////////////////////////////////////////////////////
// Solution complexity :
// Time : o(mn)
// space : O(mn)
///////////////////////////////////////////////////////////////////
class Solution {
public:
    int uniquePaths(int m, int n) 
    {
     vector<vector<int>> grid(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            grid[i][n-1] = 1;
        }
        for (int j = 0; j < n; j++) {
            grid[m-1][j] = 1;
        }
        for (int i = m-2; i >= 0; i--) {
            for (int j = n-2; j >= 0; j--) {
                grid[i][j] = grid[i + 1][j] + grid[i][j + 1];
            }
        }
        
        return grid[0][0];
    }
};