//Source : https://practice.geeksforgeeks.org/problems/peak-element/1#
//Author : Rakshitaa Geetha Mohan
//email ID : rakshitaagm@gmail.com
//Date : 07/09/2022
//Difficulty level : Easy
///////////////////////////////////////////////////////////////////
//Problem Description
// An element is called a peak element if its value is not smaller than 
// the value of its adjacent elements(if they exists).
// Given an array arr[] of size N, Return the index of any one of its peak elements.
// Example 1:
// Input: 
// N = 3
// arr[] = {1,2,3}
// Possible Answer: 2
// Generated Output: 1
// Explanation: index 2 is 3.
// It is the peak element as it is 
// greater than its neighbour 2.
// If 2 is returned then the generated output will be 1 else 0.
///////////////////////////////////////////////////////////////////
class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
       // Your code here
       int max = arr[0];
       int index = 0;
       for(uint i = 0; i < n; i++)
       {
           if(max < arr[i])
           {
                max = arr[i];
                index = i;
           }
       }
       return index;
    }
};