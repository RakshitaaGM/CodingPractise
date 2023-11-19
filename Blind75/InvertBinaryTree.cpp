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
// key learnings
// Used recursive
// Had to check whether the lft or right node is null or not
// Had to check whetehr the root node is null or not
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // auto leftNode = root->left;
        // auto rightNode = root->right;
        if(root == NULL)
            return NULL;
        if(root->left != NULL || root->right != NULL)
        {
            TreeNode* temp = root->left ;
            root->left = root->right;
            root->right = temp;
            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
    }
};