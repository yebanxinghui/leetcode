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
    //dfs
    void track(TreeNode* root,vector<vector<int>> &v,int count)
    {
        if(root == nullptr) return ;
        if(count == v.size()) v.resize(count+1);
        v[count].push_back(root->val);
        track(root->left,v,count+1);
        track(root->right,v,count+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {   
        vector<vector<int>> v;
        track(root,v,0);
        return v;
    } 
    /*bfs
    vector<vector<int>> levelOrder(TreeNode* root) {
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
            ans.push_back(v);
        }
        return ans;
    }*/
};