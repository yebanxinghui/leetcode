class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        return nums.size()>st.size();
    }
};