class Solution {
public:
    bool check(const string &s, int begin, int end)
    {
        while(begin<=end)
        {
            if(s[begin] != s[end]) return false;
            begin++;
            end--;
        }
        return true;
    }
    void backtrack(vector<vector<string>> &res, const string &s, int begin, const int size, vector<string> &tmp)
    {
        if(begin >= size)
        {
            res.push_back(tmp);
            return ;
        }
        for(int i = begin; i < size; i++)//尾部
        {
            if(check(s,begin,i))
            {
                tmp.push_back(s.substr(begin,i-begin+1));
                backtrack(res,s,i+1,size,tmp);
                tmp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if(s.empty()) return res;
        vector<string> tmp;
        backtrack(res,s,0,s.size(),tmp);
        return res;
    }
};