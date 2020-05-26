class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pos = nums.size() - 1;
        while(pos > 0 && nums[pos] <= nums[pos-1]) pos--;
        reverse(nums.begin()+pos,nums.end());
        if(pos > 0)
        {
            auto iter = upper_bound(nums.begin()+pos,nums.end(),nums[pos-1]);
            swap(nums[pos-1],*iter);
        }
    }
};