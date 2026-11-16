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
    void dfs(TreeNode* node, int& max, int curr){
        if(!node) {
            if(max < curr){
                max = curr;
            }
            return;
        }
        curr++;
        dfs(node->left, max, curr);
        dfs(node->right, max, curr);
    }

    int maxDepth(TreeNode* root) {
        int max = 0;
        int curr = 0;
        dfs(root, max, curr);
        return max;
    }
};