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
    int dfs(TreeNode* node, int& maxVal){
        if(!node) return 0;
        int left = dfs(node->left, maxVal);
        int right = dfs(node->right, maxVal);
        int curr = left + right;
        if(curr > maxVal) maxVal = curr;
        return max(left, right) + 1;
    }


    int diameterOfBinaryTree(TreeNode* root) {
        int max = 0;
        dfs(root, max);
        return max;
    }
};