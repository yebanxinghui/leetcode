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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue<TreeNode *> list;
        list.push(root);
        while(!list.empty())
        {
            vector<int> v;
            int count = list.size();
            while(count>0)
            {
                TreeNode *tmp = list.front();
                v.push_back(tmp->val);
                list.pop();
                if(tmp->left!=nullptr) list.push(tmp->left);
                if(tmp->right!=nullptr) list.push(tmp->right);
                count--;
            }
            ans.insert(ans.begin(),v);
        }
        return ans;
    }
};