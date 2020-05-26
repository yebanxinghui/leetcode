class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        else if(nums.size() == 1) return nums[0];
        vector<int> maxnum(nums);
        vector<int> minnum(nums);
        for(int i=1;i<nums.size();i++)
        {
            maxnum[i] = max(minnum[i-1] * nums[i],max(maxnum[i-1] * nums[i],nums[i]));
            minnum[i] = min(minnum[i-1] * nums[i],min(maxnum[i-1] * nums[i],nums[i]));
        }
        return *max_element(maxnum.begin(),maxnum.end());
    }
};