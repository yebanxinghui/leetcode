class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> v;
        if(len<3) return v;
        sort(nums.begin(),nums.end());
        for(int i=0;i<len-2;i++)
        {
            if(nums[i]>0) return v;
            if(i>0 && nums[i]==nums[i-1]) continue;
            int L = i+1;
            int R = len-1;
            while(L<R)
            {
                if(nums[i] + nums[L] + nums[R] == 0)
                {
                    v.push_back({nums[i],nums[L],nums[R]});
                    while(L<R && nums[L] == nums[L+1])
                        L++;
                    while(L<R && nums[R] == nums[R-1])
                        R--;
                    L++;
                    R--; 
                }
                else if(nums[i] + nums[L] + nums[R] > 0)
                    R--;
                else L++;
            }
        }
        return v;
    }
};