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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(0,nums.size()-1,nums);
    }
    TreeNode *dfs(int left,int right,vector<int>& nums)
    {
        if(left > right) return nullptr;
        int mid = (left+right)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = dfs(left,mid-1,nums);
        root->right = dfs(mid+1,right,nums);
        return root;
    }
};