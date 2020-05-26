class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        int dp[len];
        int maxnum = 1;
        for(int i=0;i<len;i++)
        {
            dp[i]=1;
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                    dp[i] = max(dp[i],dp[j]+1);
            }
            maxnum = max(maxnum,dp[i]);
        }
        return maxnum;
    }
};