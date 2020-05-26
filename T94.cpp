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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> S;
        vector<int> v;
        TreeNode* rt = root;
        while(rt || S.size()){
            while(rt){
                S.push(rt->right);
                v.push_back(rt->val);
                rt=rt->left;
            }
            rt=S.top();S.pop();
        }
        return v;
        //vector<int> v;
        //return track(root,v);
    }
    vector<int> track(TreeNode *root,vector<int> &v)
    {
        if(root!=nullptr)
        {
            if(root->left!=nullptr)
                track(root->left,v);
            v.push_back(root->val);
            if(root->right!=nullptr)
                track(root->right,v);
        }
        return v;
    }
};