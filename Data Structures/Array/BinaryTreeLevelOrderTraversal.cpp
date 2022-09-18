//Source : 
//Author : Rakshitaa Geetha Mohan
//email ID : rakshitaagm@gmail.com
//Date : 09/17/2022
//Difficulty level : Medium
///////////////////////////////////////////////////////////////////
// Given the root of a binary tree, return the level order traversal of its 
// nodes' values. (i.e., from left to right, level by level).
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]
// ///////////////////////////////////////////////////////////////////
// Solution:
// Use queue. 
// Solution complexity:
// Time : O(n)
// Space : O(n)
// ///////////////////////////////////////////////////////////////////
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
    vector<vector<int>> res;
        if(root == NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            uint count = q.size();
            vector<int>curr;
            for(uint i = 0; i < count; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                curr.push_back(node->val);
                if(node->left != NULL)
                {
                    q.push(node->left);
                }
                if(node->right != NULL)
                {
                    q.push(node->right);
                }
            }
            res.push_back(curr);
        }
        return res;
    }
};