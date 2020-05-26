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
    void flatten(TreeNode* root) {
        /*非递归*/
        if(root == nullptr) return;
        while(root)
        {
            if(root->left)
            {
                TreeNode *t = root->left;
                while(t->right)
                    t = t->right;
                t->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }
        /*递归,变形的后序遍历，右左根*/
        if(root == nullptr) return;
        flatten(root->right);
        flatten(root->left);
        if(root->left)
        {
            TreeNode *t = root->left;
                while(t->right)
                    t = t->right;
                t->right = root->right;
                root->right = root->left;
                root->left = nullptr;
        }
    }
};