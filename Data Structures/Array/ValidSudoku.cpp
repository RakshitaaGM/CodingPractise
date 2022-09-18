//Source : https://leetcode.com/problems/valid-sudoku/
//Author : Rakshitaa Geetha Mohan
//email ID : rakshitaagm@gmail.com
//Date : 09/17/2022
//Difficulty level : Medium
///////////////////////////////////////////////////////////////////
// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells 
// need to be validated according to the following rules:

// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
// Note:

// A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// Only the filled cells need to be validated according to the mentioned rules.
// Input: board = 
// [["8","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: false
///////////////////////////////////////////////////////////////////
// Solution :
// Have a bool 2D array to check rows and columns. Set the corresponding to true.
//  For squares, each box can be mapped to a number using : (r/3) * 3 + (c /3) and set
// the numbers in the boxes to true when found.
// solution complexity:
// Time = n^2
// Space = n^2
//////////////////////////////////////////////////////////////////
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
      bool row[9][9] = {false};
      bool col[9][9] = {false};
      bool square[9][9] = {false};
      for(uint r = 0; r < 9; r++)
      {
          for(uint c = 0; c < 9; c++)
          {
              if(board[r][c] == '.')
                  continue;
              
              int num = board[r][c] - '0' -1;
              int sq = (r/3) * 3 + (c/3);
              if(row[r][num] || col[c][num] || square[sq][num])
                  return false;
              row[r][num] = true;
              col[c][num] = true;
              square[sq][num] = true;
          }
      }
        return true;
    }
};