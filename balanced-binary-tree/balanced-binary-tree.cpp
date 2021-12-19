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
    pair<bool,int> height(TreeNode* root){
        if(!root){
            return {1,0};
        }
        pair<bool,int>lft=height(root->left);
        pair<bool,int>rght=height(root->right);
        bool ans=lft.first&rght.first;
        if(abs(lft.second-rght.second)>1){
            return {ans&0,1+max(lft.second,rght.second)};
        }
        return {ans,1+max(lft.second,rght.second)};
    }
    bool isBalanced(TreeNode* root) {
        return height(root).first;
    }
};