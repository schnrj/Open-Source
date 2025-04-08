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
    TreeNode* build(TreeNode*root,int value){
        if(!root){
            return root=new TreeNode(value);
        }
        if(root->val>value){
            root->left=build(root->left,value);
        }
      else{
            root->right=build(root->right,value);
        }

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode*root=nullptr;
        for(auto x:preorder){
           root= build(root,x);
        }
        return root;
    }
};