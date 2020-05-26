class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
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