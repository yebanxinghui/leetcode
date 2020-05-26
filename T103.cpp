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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        deque<TreeNode *> list;
        bool flag = true;
        list.push_back(root);
        while(!list.empty())
        {
            vector<int> v;
            int count = list.size();
            TreeNode *tmp;
            while(count>0)
            {
                if(flag){//前取后放
                    tmp = list.front();
                    list.pop_front();
                    if(tmp->left!=nullptr) list.push_back(tmp->left);
                    if(tmp->right!=nullptr) list.push_back(tmp->right);
                }
                else{//后取前放
                    tmp = list.back();
                    list.pop_back();
                    if(tmp->right!=nullptr) list.push_front(tmp->right);
                    if(tmp->left!=nullptr) list.push_front(tmp->left);
                }
                v.push_back(tmp->val);
                count--;
            }
            flag = !flag;
            ans.push_back(v);
        }
        return ans;
    }
};