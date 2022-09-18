//Source : https://leetcode.com/problems/longest-consecutive-sequence/
//Author : Rakshitaa Geetha Mohan
//email ID : rakshitaagm@gmail.com
//Date : 09/17/2022
//Difficulty level : Medium
///////////////////////////////////////////////////////////////////
// Given an unsorted array of integers nums, return the length of the 
// longest consecutive elements sequence.
// You must write an algorithm that runs in O(n) time.
// Example 1:
// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
// Example 2:
// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9
///////////////////////////////////////////////////////////////////
//Solution : 
// When the sequence starts, there won't be a numer-1 in the array. If that's
// the case, then find the numbers after it and count it
// Solution complexity:
// Time: O(n)
// space : O(n)
///////////////////////////////////////////////////////////////////
class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> s(nums.begin(), nums.end());
        uint longest = 0;
        for(auto num : nums)
        {
            uint length = 0;
            if(!s.count(num - 1))
            {
               length++;
                while(s.count(num + length))
                    length++;
            }
            longest = max(longest, length);
        }
     return longest;   
    }
};