//Source : https://leetcode.com/problems/running-sum-of-1d-array/
//Author : Rakshitaa Geetha Mohan
//email ID : rakshitaagm@gmail.com
//Date : 07/04/2022
//Difficulty level : Easy
//////////////////////////////////////////////////////////////////////////////////////////////
// Description
// Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
// Return the running sum of nums.
// Example 1:
// Input: nums = [1,2,3,4]
// Output: [1,3,6,10]
// Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
// Example 2:
// Input: nums = [1,1,1,1,1]
// Output: [1,2,3,4,5]
// Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) 
    {
        vector<int> res;
        int sum = 0;
        for(unsigned int i = 0; i < nums.size(); i++)
        {
          sum = sum + nums[i];
          res.emplace_back(sum);
        }
        return res;
    }
};
