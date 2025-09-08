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

    TreeNode* solve(TreeNode*root,int val,int depth,int cur){
        if(!root) return root;
        if(cur==depth-1){
            TreeNode*nleft=root->left;
            TreeNode*nright=root->right;
            root->left=new TreeNode(val);
            root->right=new TreeNode(val);
            root->left->left=nleft;
            root->right->right=nright;
            return root;
        }
        solve(root->left,val,depth,cur+1);
        solve(root->right,val,depth,cur+1);
        return root;

    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newnode=new TreeNode(val);
            newnode->left=root;
            return newnode;
        }
         return solve(root,val,depth,1);
    }
};