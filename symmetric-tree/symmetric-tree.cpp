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
    bool dfs(TreeNode* l,TreeNode*r){
        if(!l && !r)return 1;
        if(!r || !l)return 0;
        if(r->val!=l->val)return 0;
        return dfs(l->right,r->left) && dfs(l->left,r->right);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)return 1;
        return dfs(root->left,root->right);
    }
};