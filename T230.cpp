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
private:
    int res;
    int n = 0;
public:
    void dfs(TreeNode* root,int k)
    {
        if(root == nullptr) return ;
        dfs(root->left,k);
        n++;
        if(n == k) res = root->val;
        dfs(root->right,k);
    } 
    int kthSmallest(TreeNode* root, int k) {
        dfs(root,k);
        return res;
    }
};