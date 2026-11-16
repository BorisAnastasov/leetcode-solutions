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
    bool dfs(TreeNode* leftNode, TreeNode* rightNode){
        if(!leftNode && !rightNode) return true;
        if(!leftNode || !rightNode) return false;
        if (rightNode->val != leftNode->val) return false;
        
        return dfs(leftNode->right, rightNode->left) 
        && dfs(leftNode->left, rightNode->right);
    }

    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return dfs(root->left, root->right);
    }
};