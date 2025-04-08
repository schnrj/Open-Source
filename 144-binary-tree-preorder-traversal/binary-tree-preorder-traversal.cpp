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
// void print(TreeNode*root,vector<int>&ans){
//     if(!root) return;
//     ans.push_back(root->val);
//     print(root->left,ans);
//     print(root->right,ans);

// }
    vector<int> preorderTraversal(TreeNode* root) {
        // vector<int>ans;
//        print(root,ans);
// return ans;
      vector<int> ans;
    if (!root) return ans;

    stack<TreeNode*> s;
    s.push(root);

    while (!s.empty()) {
        TreeNode* top = s.top();
        s.pop();
        ans.push_back(top->val);

     
        if (top->right) {
            s.push(top->right);
        }
        if (top->left) {
            s.push(top->left);
        }
    }
    return ans;
    }
};