class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
    int start = 0;
    if(len == 0 || len == 1)
        return s;
    int maxlen = 1;
    int dp[len][len];
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
            dp[i][j] = 0;
    }
    for(int i=0;i<len;i++)///先初始化长度为1和2的情况
    {
        dp[i][i]=1;
        if(i<len-1&&s[i]==s[i+1])
        {
            dp[i][i+1]=1;
            maxlen = 2;
            start = i;
        }
    }
    for(int i=3;i<=len;i++)///从长度为3开始
    {
        for(int j=0;j<len-i+1;j++)
        {
            int k = j+i-1;
            if(s[j]==s[k] && dp[j+1][k-1]==1)
            {
                dp[j][k]=1;
                maxlen = i;
                start = j;
            }
        }
    }
        return s.substr(start,maxlen);
    }
};