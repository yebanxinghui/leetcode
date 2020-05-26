class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max_sum = nums[0];
        int sum = max_sum;
        for(int i=1;i<n;i++){
            if(sum < 0) sum = nums[i];
            else sum+=nums[i];
            if(sum>max_sum) max_sum = sum;
        }
        return max_sum;
    }
};