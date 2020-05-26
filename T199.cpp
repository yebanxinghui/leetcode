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
    vector<int> rightSideView(TreeNode* root) {
        //深度优先搜索，dfs，顺序是根右左
        unordered_map<int,int> m;
        int maxdepth = -1;

        stack<TreeNode*> nodeStack;
        stack<int> depthStack;
        /*广度优先遍历，使用层序遍历，最右边那个即为所求结点
        queue<TreeNode*> nodeStack;
        queue<int> depthStack;
        */
        nodeStack.push(root);
        depthStack.push(0);

        while(!nodeStack.empty())
        {
            TreeNode* node = nodeStack.top();/*nodeStack.front()*/
            nodeStack.pop();
            int depth = depthStack.top();/*depthStack.front()*/
            depthStack.pop();

            if(node!=nullptr)
            {
                maxdepth = max(depth,maxdepth);
                //如果不存在本深度的结点，则记录，此时即为最右边点
                if(m.find(depth) == m.end())
                    m[depth] = node->val;
                /*不断更新答案
                m[depth] = node->val;
                */
                nodeStack.push(node->left);
                nodeStack.push(node->right);
                depthStack.push(depth + 1);
                depthStack.push(depth + 1);
            }
        }

        vector<int> v;
        for (int i = 0; i <= maxdepth; ++i) {
            v.push_back(m[i]);
        }

        return v;
    }
};