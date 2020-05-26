class Solution {
    vector<string> v = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        vector<string> tmp;
        if(digits.empty()) return tmp; 
        string s = "";
        int n = digits.size();
        backtrack(tmp,s,0,n,digits); 
        return tmp;
    }
    void backtrack(vector<string> &vs, string &s, int count,int n, string digits)
    {
        if(count == n) vs.push_back(s);
        else{
            int num = digits[count] - '0';
            for(int i=0;i<v[num].size();i++)
            {
                s+=v[num][i];
                backtrack(vs, s, count+1, n,digits);
                s.pop_back();
            }
        }
    }
};