/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root)
    {
        if(root == nullptr) return 0;
        else return (max(height(root->left),height(root->right))+1);
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;
        //老板断气，老板身体健康
        if(abs(height(root->left)-height(root->right))<=1)
            return isBalanced(root->left)&&isBalanced(root->right);
        else return false;
    }
};