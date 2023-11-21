/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Notes 
// The leftside of the root is smallert han the root and the right of the root is greater 
// than the root itself.
// When p and q are on the either side of the roots, then the lca is root itself
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        else if(p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        else
            return root;

    }
};