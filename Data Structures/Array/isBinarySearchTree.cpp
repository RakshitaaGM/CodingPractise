//Source : https://leetcode.com/problems/validate-binary-search-tree/
//email ID : rakshitaagm@gmail.com
//Date : 07/20/2022
//Difficulty level : Easy
///////////////////////////////////////////////////////////////////
//Problem Description
// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// A valid BST is defined as follows:

// -The left subtree of a node contains only nodes with keys less than the node's key.
// -The right subtree of a node contains only nodes with keys greater than the node's key.
// -Both the left and right subtrees must also be binary search trees.
// Approach based on solutions in Discussions
///////////////////////////////////////////////////////////////////
class Solution {
public:
    bool BST(TreeNode* root, long long min, long long max)
    {
        if(root == NULL)
        {
            return true;
        }
        if(root->val > min && root->val < max)
        {
            bool left = BST(root->left, min, root->val);  // Makes sure the node values are lesser than the root value
            bool right = BST(root->right, root->val, max); // Makes sure that the node values are greater than the root value
            return left&&right;
        }
        return false;           
    }
    
    bool isValidBST(TreeNode* root) 
    {
       return BST(root, LONG_MIN, LONG_MAX); // lower bound, upper bound
    }
};