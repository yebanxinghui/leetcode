class Solution {
public:
    int longestValidParentheses(string s) {
        int maxans = 0;
        stack<int> stack;
        stack.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if (stack.empty()) {
                    stack.push(i);
                } else {
                    maxans = max(maxans, i - stack.top());
                }
            }
        }
        return maxans;
    }
};
/*
int len = s.size();
        vector<int> dp(len,0);
        int maxLen = 0;
        for(int i = 1; i < len; i++)
        {
            if(s[i] == ')')
            {
                if(s[i-1] == '(')
                {
                    if(i-2>=0) dp[i] = dp[i-2]+2;
                    else dp[i] = 2;
                }
                else if(dp[i-1] > 0)
                {
                    if(i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '(')
                    {
                        if(i-dp[i-1]-2>=0)
                            dp[i] = dp[i-1] + dp[i-dp[i-1]-2] + 2;
                        else 
                            dp[i] = dp[i-1]+2;
                        
                            
                    }                
                }
                maxLen = max(maxLen,dp[i]);
            }
        }
        return maxLen;
*/