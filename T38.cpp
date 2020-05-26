class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for(int i=2;i<=n;i++)
        {
            s+=" ";
            string tmp = "";
            int num = 1;
            char ch = s[0];
            for(int j=1;j<s.length();j++)
            {
                if(s[j]==ch) num++;
                else{
                    tmp = tmp + to_string(num) + ch;
                    num = 1;
                    ch = s[j];
                }
            }
            s = tmp;
            tmp = "";
        }
        return s;
    }
};