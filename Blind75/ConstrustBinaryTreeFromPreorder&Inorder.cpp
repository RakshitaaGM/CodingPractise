// Watch neetcode's video
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         if(preorder.empty() || inorder.empty())
            return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        root->val = preorder[0];
        vector<int> preOrderLeft;
        vector<int> inOrderLeft;
        auto mid = find(inorder.begin(), inorder.end(), preorder[0]);
        int midPoint = mid - inorder.begin();
        for(int i = 1; i <= midPoint; i++)
        {
            preOrderLeft.emplace_back(preorder[i]);
        }
        for(int i = 0; i < midPoint; i++)
        {
            inOrderLeft.emplace_back(inorder[i]);
        }
        vector<int> preOrderRight;
        vector<int> inOrderRight;
        for(int i = midPoint + 1; i < preorder.size(); i++)
        {
            preOrderRight.emplace_back(preorder[i]);
        }
        for(int i = midPoint + 1; i < inorder.size(); i++)
        {
            inOrderRight.emplace_back(inorder[i]);
        }
        root->left = buildTree(preOrderLeft, inOrderLeft);
        root->right = buildTree(preOrderRight, inOrderRight);
        return root;
    }
};