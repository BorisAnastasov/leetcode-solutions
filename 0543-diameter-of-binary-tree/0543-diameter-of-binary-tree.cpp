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
        int leftH = dfs(node->left, maxVal);
        int rightH = dfs(node->right, maxVal);
        int curr = leftH + rightH;
        if(curr > maxVal) maxVal = curr;

        return 1 + max(leftH, rightH);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int max = 0;
        dfs(root, max);
        return max;
    }
};