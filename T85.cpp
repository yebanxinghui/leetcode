class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int maxarea = 0;
        vector<int> dp(n,0);
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == '1')
                    dp[j]++;
                else dp[j] = 0;
            }
            maxarea = max(maxarea,largestRectangleArea(dp));
        }
        return maxarea;

    }
    int largestRectangleArea(vector<int>& v) {
        vector<int> heights(v);
        int ans = 0;
        stack<int> st;//存的是索引，不是高度
        //首位均为0
        heights.insert(heights.begin(),0);
        heights.push_back(0);
        for(int i=0;i<heights.size();i++)
        {
            while(!st.empty() && heights[st.top()]>heights[i])
            {
                int cur = st.top();
                st.pop();
                int left = st.top()+1;
                int right = i;
                ans = max(ans,(right-left)*heights[cur]);
            }
            st.push(i);
        }
        return ans;
    }
};