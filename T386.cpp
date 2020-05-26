class Solution {
public:
    void dfs(vector<int> &v,int k,int n)
    {
        if(k>n) return ;
        if(k != 0) v.push_back(k);
        for(int i = 0; i < 10; i++)
        {
            int tmp = 10*k+i;
            //需要防止0的无限递归
            if(tmp>0 && tmp<=n) 
            {
                dfs(v,tmp,n);
            }
        } 
    }
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        dfs(res,0,n);
        return res;
    }
};