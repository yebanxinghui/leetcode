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
    TreeNode *ans;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == nullptr) return false;
        else{
            bool equal = (root == p || root == q);
            bool findleft = dfs(root->left,p,q);
            bool findright = dfs(root->right,p,q);
            bool tmp2 = (findleft || findright) && equal;
            bool tmp = findleft && findright;
            if(tmp || tmp2)
            {
                ans = root;
            }
            return findleft || findright || equal;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        dfs(root,p,q);
        return ans;
    }
};