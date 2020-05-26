class Solution {
public:
    void dfs(vector<int>& nums,vector<vector<int>> &v,int count,int n)
    {
        if(count == n) v.push_back(nums);
        for(int i=count;i<n;i++)
        {
            swap(nums[count],nums[i]);
            dfs(nums,v,count+1,n);
            swap(nums[count],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> v;
        dfs(nums,v,0,nums.size());
        return v;
    }
};