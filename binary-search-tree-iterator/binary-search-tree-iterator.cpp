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
class BSTIterator {
    private:
    int ind=0;
    vector<TreeNode*>inorder;
    TreeNode *curr=NULL;
public:
    void dfs(TreeNode*root){
        if(!root){
            return;
        }
        dfs(root->left);
        inorder.push_back(root);
        dfs(root->right);
    }
    BSTIterator(TreeNode* root) {
       dfs(root); 
        curr=root;
    }
    int next() {
     return inorder[ind++]->val;
        
    }
    
    bool hasNext() {
        if(ind==inorder.size())return 0;
        return 1;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */