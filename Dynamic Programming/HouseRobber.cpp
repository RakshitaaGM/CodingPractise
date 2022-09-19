//Source : https://leetcode.com/problems/house-robber/
//Author : Rakshitaa Geetha Mohan
//email ID : rakshitaagm@gmail.com
//Date : 09/17/2022
//Difficulty level : medium
///////////////////////////////////////////////////////////////////
// You are a professional robber planning to rob houses along a street. 
// Each house has a certain amount of money stashed, the only constraint 
// stopping you from robbing each of them is that adjacent houses have 
// security systems connected and it will automatically contact the police 
// if two adjacent houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each 
// house, return the maximum amount of money you can rob tonight without 
// alerting the police.
// Example 1:
// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 2:
// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.
///////////////////////////////////////////////////////////////////
// Solution:
// Find the max for base case and keep building from it. USe two variables
//  to trackthe previous 
// and the max one before that.
// Solution complexity:
// Time : O(n);
// Space  : o(1)
///////////////////////////////////////////////////////////////////
class Solution {
public:
    int rob(vector<int>& nums) 
    {
     if(nums.size() == 1)
         return nums[0];
     int rob1 = nums[0];
     int rob2 = max(nums[0], nums[1]);
     for(uint i = 2; i < nums.size(); i++)
     {
        int temp = max(nums[i] + rob1, rob2);
         rob1 = rob2;
         rob2 = temp;
     }
      return rob2;   
    }
    
};