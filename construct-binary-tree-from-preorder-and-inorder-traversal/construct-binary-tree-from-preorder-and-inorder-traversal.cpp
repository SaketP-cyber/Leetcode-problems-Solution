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
    TreeNode *Helper(vector<int>& pre,vector<int>&in,int preS,int preE,int InS,int InE){
        if(InS>InE)return NULL;
        int rootData=pre[preS];
        int ind=-1;
        for(int i=InS;i<=InE;i++){
            if(in[i]==rootData){
                ind =i;break;
            }
        }
        int LinS=InS;
        int LinE=ind-1;
        int RinS=ind+1;
        int RinE=InE;
        int LpreS=preS+1;
        int LpreE=LpreS+(LinE-LinS);
        int RpreS=LpreE+1;
        int RpreE=preE;
        TreeNode* node=new TreeNode(rootData);
        node->left=Helper(pre,in,LpreS,LpreE,LinS,LinE);
        node->right=Helper(pre,in,RpreS,RpreE,RinS,RinE);
        return node;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n=pre.size();
        return Helper(pre,in,0,n-1,0,n-1);
    }
};