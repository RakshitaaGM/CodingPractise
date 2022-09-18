//Source : https://leetcode.com/problems/climbing-stairs/
//Author : Rakshitaa Geetha Mohan
//email ID : rakshitaagm@gmail.com
//Date : 09/17/2022
//Difficulty level : easy
///////////////////////////////////////////////////////////////////
// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct
// ways can you climb to the top?
// Example 1:
// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps
///////////////////////////////////////////////////////////////////
class Solution {
public:
    int climbStairs(int n) 
    {
        int t1 = 0;
        int t2 = 1;
        int res = 0;

    for(int i = 1; i<=n; i++) {
        res = t1 + t2;
        t1 = t2;
        t2 = res;
    }
        return res;
    }
};