class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(res,tmp,candidates,target,0,0);
        return res;
    }
    void dfs(vector<vector<int>> &res,vector<int> &tmp,vector<int> candidates,int target,int begin,int sum)
    {
        if(sum == target)
            res.push_back(tmp);
        else
        {
            for(int i = begin;i < candidates.size(); i++)
            {
                if(sum + candidates[i] <= target)
                {
                    tmp.push_back(candidates[i]);
                    dfs(res,tmp,candidates,target, i ,sum + candidates[i]);
                    tmp.pop_back();
                }
            }
        }
    }
};