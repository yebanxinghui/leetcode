class Solution {
public:
    void dfs(vector<string> &v,string s, int left, int right)
    {
        if(left==0 && right==0)
        {
            v.push_back(s);
            return ;
        }
        else if(left >= 0&& right>=0)
        {
            if(left > right) return ;
            dfs(v,s+"(",left-1,right);
            dfs(v,s+")",left,right-1);
        }

    }

    vector<string> generateParenthesis(int n) {
       vector<string> ans;
       string s;
       dfs(ans,s,n,n);
       return ans;
       /*vector<vector<string> > v(n+1);
        v[0].push_back("");
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                for(string &s1 : v[j])
                    for(string &s2 : v[i-j-1])
                        v[i].push_back("("+s2+")"+s1);
            }
        }
        return v[n];*/
    }
};