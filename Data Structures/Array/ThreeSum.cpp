//Source : https://leetcode.com/problems/3sum/
//Author : Rakshitaa Geetha Mohan
//email ID : rakshitaagm@gmail.com
//Date : 09/17/2022
//Difficulty level : Medium
///////////////////////////////////////////////////////////////////
// Given an integer array nums, return all the triplets [nums[i], nums[j],
// nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + 
// nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.
// Example 1:
// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.
// Example 2:
// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.
// Example 3:
// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.
///////////////////////////////////////////////////////////////////
// Solution complexity:
// Time: O(n^2)
// Space : O(n^2)
///////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(uint i = 0;i < nums.size() - 2; i++)
        {
            if(i==0 || i>0 && nums[i]!=nums[i-1])
            {
                uint l = i+1; uint r = nums.size() - 1;
                while(l < r)
                {
                   int sum = nums[i] + nums[l] + nums[r];
                    if(sum > 0)
                    {
                        r--;
                    }
                    else if(sum < 0)
                    {
                        l++;
                    }
                    else
                    {
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[l]);
                        tmp.push_back(nums[r]);
                        res.push_back(tmp);
                        while(l<r && (nums[l]==nums[l+1]))l++;
                        while(l<r && (nums[r]==nums[r-1]))r--;
                        l++;r--;
                    } 
                }
                
            }
        }
        return res;
    }
};