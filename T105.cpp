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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len1 = inorder.size();
        if(len1 == 0) return nullptr;
        unordered_map<int,int> m;
        int preIndex = 0;
        for(int i=0;i<len1;i++)
        {
            m[inorder[i]] = i;
        }
        return builder(0,len1-1,preorder,m,preIndex);
    }
    TreeNode *builder(int left,int right,vector<int>& preorder,unordered_map<int,int> &m,int &preIndex)
    {
        if(left>right) return nullptr;
        int cur = preorder[preIndex];
        ++preIndex;
        TreeNode *curNode = new TreeNode(cur);
        curNode->left = builder(left, m[cur]-1, preorder, m,preIndex);
        curNode->right = builder(m[cur]+1, right,preorder, m,preIndex);
        return curNode;
    }
};