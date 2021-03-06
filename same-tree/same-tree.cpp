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
    bool dfs(TreeNode *p,TreeNode*q){
        if(p==NULL && q==NULL){
            return true;
        }
        else if(p==NULL && q!=NULL || p!=NULL && q==NULL){
            return false;
        }
        if(p->val !=q->val)return false;
        bool ans=true;
        ans&=dfs(p->left,q->left);
        ans&=dfs(p->right,q->right);
        return ans;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p,q);
    }
};