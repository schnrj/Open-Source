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
#define pn pair<TreeNode*,int>
pn findLCA(TreeNode*root){
    if(root==NULL){
        return make_pair(root,0);
    }
    pn left=findLCA(root->left);
    pn right=findLCA(root->right);
    if(left.second==right.second){
        return make_pair(root,1+left.second);
    }
    else if(left.second>right.second){
        return make_pair(left.first,1+left.second);
    }
    // else if(left.second<right.second){
        return make_pair(right.first,1+right.second);
    // }
}
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        pn sachu=findLCA(root);
        return sachu.first;
    }
};