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
    bool isValidBST(TreeNode* root) {
        if(root==nullptr) return true;
        vector<int> ans;
        track(root,ans);
        for(int i=1;i<ans.size();i++)
        {
            if(ans[i]<=ans[i-1]) return false;
        }   
        return true;
    }
    void track(TreeNode *root,vector<int> &ans)
    {
        if(root!=nullptr)
        {
            if(root->left!=nullptr)
                track(root->left,ans);
            ans.push_back(root->val);
            if(root->right!=nullptr)
                track(root->right,ans);
        }
    }
};