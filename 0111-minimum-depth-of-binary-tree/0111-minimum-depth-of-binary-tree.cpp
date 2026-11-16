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
    void dfs(TreeNode* node, int& min, int curr){
        if(!node) return;
        if(curr >= min) return;
        if(!node->left && !node->right){
            if(min > curr) min = curr;
            return;
        }
        curr++;
        dfs(node->right, min, curr);
        dfs(node->left, min, curr);
    }

    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int min = 2e9;
        int curr = 1;
        dfs(root, min, curr);
        return min;
    }
};