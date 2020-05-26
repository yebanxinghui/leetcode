class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<vector<int>> v;
        if(len<4) return v;
        sort(nums.begin(),nums.end());
        for(int i=0;i<len-3;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<len-2;j++)
            {
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int L = j+1;
                int R = len-1;
                while(L<R)
                {
                    if(nums[i] + nums[j] + nums[L] + nums[R] == target)
                    {
                        v.push_back({nums[i],nums[j],nums[L],nums[R]});
                        while(L<R && nums[L] == nums[L+1])
                            L++;
                        while(L<R && nums[R] == nums[R-1])
                            R--;
                        L++;
                        R--; 
                    }
                    else if(nums[i] + nums[j] + nums[L] + nums[R] > target)
                        R--;
                    else L++;
                }
            }
        }
        return v;
    }
};