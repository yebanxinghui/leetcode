class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        stack<int> s1,s2;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(int i=0;i<intervals.size();i++)
        {
            int left = intervals[i][0];
            int right = intervals[i][1];
            if(s1.empty())
            {
                s1.push(left);
                s2.push(right);
            }
            else if(s1.top() <= left && s2.top() >= right) continue;
            else if(s1.top() <= left && left <= s2.top() && s2.top() <= right)
            {
                s2.pop();
                s2.push(right);
            }
            else if(s2.top() < left)
            {
                ans.push_back({s1.top(),s2.top()});
                s1.pop();
                s2.pop();
                s1.push(left);
                s2.push(right);
            }
        }
        if(!s1.empty())
        {
            ans.push_back({s1.top(),s2.top()});
        }
        return ans;
        
        /*if(intervals.size() < 2) return intervals;
        int len = intervals.size();
        sort(intervals.begin(),intervals.end());
        int left = 0, right = 1;
        vector<vector<int> > ans;
        while(right < len)
        {
            if(intervals[right][0]>intervals[left][1])
            {
                ans.push_back(intervals[left]);
                left = right;
            }
            else if(intervals[right][1] <= intervals[left][1])
                ++right;
            else{
                intervals[left][1] = intervals[right][1];
                ++right;
            }
        }
        ans.push_back(intervals[left]);
        return ans;*/
    }
};