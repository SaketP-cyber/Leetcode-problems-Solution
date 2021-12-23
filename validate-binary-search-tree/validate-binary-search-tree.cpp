class Solution {
public:
    class Node{
        public:
      long long mini;
        long long maxi;
        bool isBST;
        Node(){
            maxi=LONG_MIN;
            mini=LONG_MAX;
            isBST=1;
        }
    };
    Node dfs(TreeNode*root){
        if(!root){
            Node n;
            return n;
        }
        Node lft=dfs(root->left);
        Node rght=dfs(root->right);
        Node res;
        if(lft.isBST && rght.isBST){
            if(root->val>lft.maxi && root->val<rght.mini){
                res.mini=min({(long long)root->val,lft.mini,rght.mini});
                res.maxi=max({(long long)root->val,lft.maxi,rght.maxi});
                res.isBST=1;
                return res;
            }
            else{
              res.isBST=0;
            return res; 
            }
        }
        else{
            res.isBST=0;
            return res;
        }
    }
    bool isValidBST(TreeNode* root) {
        if(!root->right && !root->left)return 1;
        return dfs(root).isBST;
    }
};