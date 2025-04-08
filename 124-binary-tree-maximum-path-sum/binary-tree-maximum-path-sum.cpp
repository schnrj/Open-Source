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
    int find(TreeNode*root,int &res){
        if(!root){
            return 0;
        }
        int left=find(root->left,res);
        int right=find(root->right,res);
        int ms=max(max(left,right)+root->val,root->val);  
        int maxx=max(ms,left+right+root->val);   
        res=max(res,maxx);
        return ms;
    }
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        find(root,res);
        return res;
    }
};