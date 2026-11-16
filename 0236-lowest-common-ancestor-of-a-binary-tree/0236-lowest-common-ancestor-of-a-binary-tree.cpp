/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* node, TreeNode* target, vector<TreeNode*>& v, bool& found){
        if (!node || found) return;

        v.push_back(node);

        if(node == target){
            found = true;
            return;
        }

        dfs(node->left, target, v, found);
        dfs(node->right, target, v, found);


        if(!found) v.pop_back();
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> arrP;
        vector<TreeNode*> arrQ;
        bool qFound = false, pFound = false;
        dfs(root, p, arrP, pFound);
        dfs(root, q, arrQ, qFound);
        TreeNode* lca = nullptr;
        int i = 0;
        
        while (i < arrP.size() && i < arrQ.size() && arrP[i] == arrQ[i]) {
            lca = arrP[i];
            i++;
        }
        
        return lca;
    }
};