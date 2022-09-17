//Source : https://leetcode.com/problems/group-anagrams/
//Author : Rakshitaa Geetha Mohan
//email ID : rakshitaagm@gmail.com
//Date : 09/17/2022
//Difficulty level : Medium
///////////////////////////////////////////////////////////////////
// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
// typically using all the original letters exactly once.

 

// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
// Example 2:

// Input: strs = [""]
// Output: [[""]]
// Example 3:

// Input: strs = ["a"]
// Output: [["a"]]
///////////////////////////////////////////////////////
//Solution
// Create a hashmap with charCount Array as key and the strings as value
// charCount array is a zero array of length 26
// append the hashMap.second to form a vector of vecot of strings
// solution complexity
// time : m * n * 26 = O(m * n)
// Space : O(n)
///////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        map<vector<int>, vector<string>>hashMap;
        for(auto str : strs)
        {
            vector<int> count(26);
            for(uint i = 0; i < str.length();i++)
            {
                count[str[i] - 'a']++;
            }
            hashMap[count].push_back(str);
        }
        vector<vector<string>> res;
        for(auto keyValue : hashMap)
        {
            res.push_back(keyValue.second);
        }
        return res;
    }
};