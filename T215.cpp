class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int result = 0;
        int len = nums.size();
        if(len == 0 || k > len) return 0;
        priority_queue<int, vector<int>,greater<int>> store;
        for(int i = 0; i < len; i++)
        {
            store.push(nums[i]);
            if(store.size()>k)
                store.pop();
        }
        result = store.top();
        return result;
    }
};