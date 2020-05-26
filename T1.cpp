class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;//unordered_map内部是由哈希表实现的，map是红黑树
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]=i;
            if(m.find(target-nums[i]) != m.end() && m[target-nums[i]]!=i)
                return {m[target-nums[i]],i};
        }
        return {};
    }
};