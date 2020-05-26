class Solution {
public:
    bool isMatch(string s, string p) {
        //自底向上dp
        bool dp[s.length()+1][p.length()+1];
        for(int i=0;i<s.length()+1;i++)
            for(int j=0;j<p.length()+1;j++)
                dp[i][j]=false;
        // 将右下角置为true
        dp[s.length()][p.length()] = true;
        // 从后向前匹配
        // i从越界开始补齐了最后一列
        // 由于dp的右下角已经赋值
        // 所以不用重复判断所以j从length-1开始
        for (int i = s.length(); i >= 0; i--) {
            for (int j = p.length()-1; j >= 0; j--) {
                // 判断字符是否相等
                bool first_match = (i < s.length() && (p[j] == s[i] || p[j] == '.'));
                // 涉及到了*号匹配
                if (j+1 < p.length() && p[j+1] == '*'){
                    // 状态转换方程
                    // 若后一个字符为*那么就涉及到了*号匹配
                    // 规律就是看看跳过两个是否匹配（也代表了*号的可以是0个匹配字符的性质）
                    // 或者老老实实匹配*号当前字符是否匹配且j不用改变i继续后移看看是否匹配
                    dp[i][j] = dp[i][j+2] || (first_match && dp[i+1][j]);
                }else {
                    // 不涉及*号的匹配
                    // 就看之前的字符是否匹配以及当前字符是否匹配即可
                    dp[i][j] = first_match && dp[i+1][j+1];
                }
            }
        }
        // dp[0][0]就代表着之后的全部匹配完成看看是否全部匹配
        return dp[0][0];
    }
};