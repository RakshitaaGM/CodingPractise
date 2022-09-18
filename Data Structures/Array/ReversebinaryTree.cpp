//Source : https://leetcode.com/problems/invert-binary-tree/
//Author : Rakshitaa Geetha Mohan
//email ID : rakshitaagm@gmail.com
//Date : 09/17/2022
//Difficulty level : Easy
///////////////////////////////////////////////////////////////////
// Given the root of a binary tree, invert the tree, and return its root.
// Input: root = [4,2,7,1,3,6,9]
// Output: [4,7,2,9,6,3,1]
// ///////////////////////////////////////////////////////////////////
// Solution : recursion
// Solution complexity: 
// Time : O(n)
// space= O(n)
///////////////////////////////////////////////////////////////////
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) 
    {
     if(root == NULL)
         return NULL;
     swap(root->left, root->right);
     invertTree(root->left);
     invertTree(root->right);
     return root; 

    }
};