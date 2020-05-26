class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> res{v};
        for(int i = 0; i < nums.size();i++){
            int len = res.size();
            for(int j = 0; j < len; j++) {
                vector<int> newSub(res[j]);
                newSub.push_back(nums[i]);
                res.push_back(newSub);
            }
        }
        return res;
    }
};