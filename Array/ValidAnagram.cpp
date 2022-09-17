//Source : https://leetcode.com/problems/valid-anagram/
//Author : Rakshitaa Geetha Mohan
//email ID : rakshitaagm@gmail.com
//Date : 09/17/2022
//Difficulty level : Easy
///////////////////////////////////////////////////////////////////
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// An Anagram is a word or phrase formed by rearranging the letters of a different word 
// or phrase, typically using all the original letters exactly once.

 

// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:

// Input: s = "rat", t = "car"
// Output: false
///////////////////////////////////////////////////////////////////
//Sort two strings and compare
class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.size()!=t.size())
            return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s==t)
            return true;
        else
            return false;
    }
};

// Without using sort
// DEclare a count array of size 26 and add 1 and subtract 1 in the position
// equal to the char and check whether the coutn array is empty at the end
class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.size() != t.size())
            return false;
        vector<int> count(26);
        for(uint i = 0;i < s.size(); i++)
        {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        for(auto a : count)
            if(a) return false;
        return true  ;     
    }
};