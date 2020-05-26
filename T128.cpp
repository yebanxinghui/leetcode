class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0;
        for(int num : nums) {
            if(s.count(num - 1)) 
                continue;
            int curLen = 1;
            int count = num;
            while(s.count(1+count++)) ++curLen;
            res = max(res, curLen);
        }
        return res;
    }
};