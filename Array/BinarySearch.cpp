//Source : https://practice.geeksforgeeks.org/problems/binary-search-1587115620/1/?page=1&category[]=Arrays&curated[]=1&sortBy=submissions#
//Author : Rakshitaa Geetha Mohan
//email ID : rakshitaagm@gmail.com
//Date : 07/10/2022
//Difficulty level : Easy
///////////////////////////////////////////////////////////////////
//Problem Description
// Given a sorted array of size N and an integer K, find the position at 
// which K is present in the array using binary search.
// Learned how a binary search algorithm works - have implemented the iterative 
// search algorithm
// Binary Search algo Source : https://www.geeksforgeeks.org/binary-search/?ref=lbp
///////////////////////////////////////////////////////////////////
class Solution {
  public:
    int binarysearch(int arr[], int n, int k) {
       int start = 0;
       int end = n-1;
       while(start <= end)
       {
          int mid = (start + end) / 2;
          if(arr[mid] < k)
          {
              start = mid + 1;
          }
          else if(arr[mid] > k)
          {
              end = mid - 1;
          }
          else if(arr[mid] == k)
          {
              return mid;
          }
       }
       return -1;
    }
};