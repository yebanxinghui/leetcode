class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans(len,1);
        ans[len-1] = nums[len-1];
        for(int i = len-2;i>=0;i--)
        {
            ans[i] = nums[i] * ans[i+1];
        }
        ans[0] = ans[1];
        for(int i = 1; i < len-1; i++)
        {
            nums[i] = nums[i] * nums[i-1];
            ans[i] = nums[i-1] * ans[i+1];
        }
        ans[len-1] = nums[len-2];
        return ans;

    }
};