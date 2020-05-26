class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res{-1,-1};
        if(nums.empty()) return res;
        int len = nums.size();
        int left = 0, right = len-1;
        while(left<right)
        {
            int mid = (left + right)/2;
            if(nums[mid]>=target) right = mid;
            else left = mid+1;
        }
        if(nums[left]!=target) return res;
        res[0] = left;
        right = len;
        while(left<right)
        {
            int mid = (left + right)/2;
            if(nums[mid]>target) right = mid;
            else left = mid+1;
        }
        res[1]=left-1;
        return res;
        //auto begin = lower_bound(nums.begin(), nums.end(), target);
        //auto end   = upper_bound(nums.begin(), nums.end(), target);
        //if (begin == end) return {-1, -1};
        //return {(int)(begin - nums.begin()), (int)(end - nums.begin() - 1)};
    }
};