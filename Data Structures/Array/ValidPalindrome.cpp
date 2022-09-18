//Source : https://leetcode.com/problems/valid-palindrome/
//Author : Rakshitaa Geetha Mohan
//email ID : rakshitaagm@gmail.com
//Date : 09/17/2022
//Difficulty level : Medium
///////////////////////////////////////////////////////////////////
// A phrase is a palindrome if, after converting all uppercase letters 
// into lowercase letters and removing all non-alphanumeric characters, 
// it reads the same forward and backward. Alphanumeric characters 
// include letters and numbers.
// Given a string s, return true if it is a palindrome, or false otherwise.
// Example 1:
// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
// Example 2:
// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.
// Example 3:
// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric characters.
// Since an empty string reads the same forward and backward, it is a palindrome.
///////////////////////////////////////////////////////////////////
// Solution
// Deal with upper, lower case letters and numbers seperately
// Solution complexity:
// Time : O(n)
// space: O(n)
///////////////////////////////////////////////////////////////////
class Solution {
public:
    bool isPalindrome(string s) 
    {
        string str;
        for(char ch : s)
        {
            if(ch >= 'a' && ch <= 'z')
            {
                str.push_back(ch);
            }
            else if(ch >= 'A' && ch <= 'Z')
            {
                str.push_back(tolower(ch));
            }
            else if(ch >='0' && ch <= '9')
            {
                str.push_back(ch);
            }
        }
        string str1(str);
        reverse(str.begin(), str.end());
        if(str1 == str)
            return true;
        return false;
    }
};