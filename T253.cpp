class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        vector<pair<int,int>> m;
        for(auto i:intervals)
        {
            m.push_back(make_pair(i[0],1));
            m.push_back(make_pair(i[1],-1));
        }
        sort(m.begin(),m.end());
        int count = 0;
        int maxvalue = 0;
        for(auto i:m)
        {
            count+=i.second;
            maxvalue = max(maxvalue,count);
        }
        return maxvalue;
    }
};