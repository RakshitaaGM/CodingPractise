//Source : https://leetcode.com/problems/top-k-frequent-elements/
//Author : Rakshitaa Geetha Mohan
//email ID : rakshitaagm@gmail.com
//Date : 09/17/2022
//Difficulty level : Medium
///////////////////////////////////////////////////////////////////
// Given an integer array nums and an integer k, return the k most frequent 
// elements. You may return the answer in any order.

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]
///////////////////////////////////////////////////////////////////
// solution
// Store the count of each number corresponding to the number itself
// in hashmap. **!!!!Hash map cannot be sorted**. Store the data again as
// vector of pairs and sort it for the count in reverse (for descending order) 
// Solution Complexity
//time : n*logn
//space : n
////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        map<int, int> hashMap;
        vector<pair<int, int>> vecMap;
        vector<int> res;
        for(uint i = 0; i < nums.size();i++)
        {
            hashMap[nums[i]]++;
        }
        for(auto map : hashMap)
        {
            vecMap.push_back(make_pair(map.second, map.first));
        }
        sort(vecMap.rbegin(), vecMap.rend());
        int c = 0;
        for(auto map : vecMap)
        {
           c++;
            res.push_back(map.second); 
            if(c == k)
                break;
        }
        return res;
        
    }
};
