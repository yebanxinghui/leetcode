class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow1 = nums[0], slow2 = nums[0], fast = nums[0];
        do {
            slow1 = nums[slow1];
            fast = nums[nums[fast]];
        } while (slow1 != fast);//判断是否有环
        while (slow1 != slow2) {//判断环入口
            slow1 = nums[slow1];
            slow2 = nums[slow2];
        }
        return slow1;
    }
};