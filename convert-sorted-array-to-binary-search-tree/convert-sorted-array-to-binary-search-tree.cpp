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
    TreeNode* Construct(int l,int h,vector<int>&nums){
        if(l>=h)return NULL;
        int mid=l+(h-l)/2;
        TreeNode *node=new TreeNode(nums[mid]);
        node->left=Construct(l,mid,nums);
        node->right=Construct(mid+1,h,nums);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return Construct(0,nums.size(),nums);
    }
};