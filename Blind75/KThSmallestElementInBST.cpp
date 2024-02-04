// Brute force method
// complexity : n^2 * long n
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
    void saveArray(TreeNode* root, vector<int>& arr)
    {
        if(root == NULL)
            return;
        saveArray(root->left, arr);
        arr.push_back(root->val);
        saveArray(root->right, arr); 
    }
    int kthSmallest(TreeNode* root, int k) {
       vector<int> arr;
       saveArray(root, arr);
       return arr[k-1]; 
    }
};
///////////////////////////////////////////////////////////////////////////////////////
