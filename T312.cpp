class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if(nums.empty()) return 0;
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int len = nums.size();
        int dp[len][len];
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<len;j++)
            {
                dp[i][j]=0;
            }
        }
        for(int i=2;i<len;i++)//区间长度
        {
            for(int left=0;left<len-i;left++)//左区间
            {
                int right = left+i;//右区间
                for(int j=left+1;j<right;j++)
                {
                    dp[left][right] = max(dp[left][right],dp[left][j]+dp[j][right]+nums[left]*nums[j]*nums[right]);
                }
            }
        }
        return dp[0][len-1];
    }
};