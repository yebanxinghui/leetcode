class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        vector<int> m(len+1,0);
        if(len==0) return 0;
        else if(len==1) return nums[0];
        m[0] = 0;
        m[1] = nums[0];
        for(int i=2;i<=len;i++)
        {
            m[i] = max(m[i-1],m[i-2]+nums[i-1]);
        }
        return m[len];

    }
};