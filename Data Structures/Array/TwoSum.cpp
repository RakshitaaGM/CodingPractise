//Source : https://leetcode.com/problems/two-sum/
//Author : Rakshitaa Geetha Mohan
//email ID : rakshitaagm@gmail.com
//Date : 07/04/2022
//Difficulty level : Easy
///////////////////////////////////////////////////////////////////
// Problem Description
// Given an array of integers nums and an integer target, return indices of 
// the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, 
// and you may not use the same element twice.
// You can return the answer in any order.
// Example 1:
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
///////////////////////////////////////////////////////////////////
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> res;
        for(uint i = 0; i < nums.size(); i++)
        {
            int diff = target - nums[i];
            auto it = find(nums.begin(), nums.end(), diff);
            uint j = (it - nums.begin());
            if( it != nums.end() && i != j)
            {
                res.emplace_back(i);
                res.emplace_back(j);
                break;
            } 
        }
       return res;
    }
};