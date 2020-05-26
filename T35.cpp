class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        int len = nums.size();
        int left = 0, right = len-1;
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) right = mid-1;
            else left = mid+1;
        }
        if(right<0 || left>=len) return left;
        else if(nums[left] > target) return left;
        return left+1;
    }
};