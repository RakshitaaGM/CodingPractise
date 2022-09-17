//Source : https://leetcode.com/problems/contains-duplicate/
//Author : Rakshitaa Geetha Mohan
//email ID : rakshitaagm@gmail.com
//Date : 09/17/2022
//Difficulty level : Easy
///////////////////////////////////////////////////////////////////
// Given an integer array nums, return true if any value appears at least twice in the array, 
// and return false if every element is distinct.
// Example 1:

// Input: nums = [1,2,3,1]
// Output: true
// Example 2:

// Input: nums = [1,2,3,4]
// Output: false
// Example 3:

// Input: nums = [1,1,1,3,3,4,3,2,4,2]
// Output: true
///////////////////////////////////////////////////////////////////
#include<iostream>
#include<vector>
// Fast - O(nlogn) and O(n)
bool containsDuplicate(vector<int>& nums) 
{
    sort(nums.begin(), nums.end());
    for(int i = 1; i < nums.size(); i++)
    {
        if(nums[i] == nums[i-1])
            return true;
    }
    return false;
}

// Time - O(n) and Space - O(n)
bool containsDuplicate(vector<int>& nums) 
{
    for(uint i = 0; i < nums.size();i++)
    {
    auto it = find(hash.begin(), hash.end(), nums[i]);
        if(it != hash.end())
        {
            return true;
        }
        hash.push_back(nums[i]);
    }
    return false;
}
