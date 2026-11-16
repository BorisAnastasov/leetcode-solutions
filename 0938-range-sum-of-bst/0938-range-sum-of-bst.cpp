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
    void dfs(TreeNode* node, int low, int high, set<int>& s, int& sum){
        if(!node) return;
        if(node->val >= low && node->val <= high){
            if(!s.contains(node->val)) {
                s.insert(node->val);
                sum+=node->val;    
            }
        }
        dfs(node->left, low, high, s, sum);
        dfs(node->right, low, high, s, sum);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        set<int> s;
        dfs(root, low, high, s, sum);
        return sum;
    }
};