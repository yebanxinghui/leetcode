class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int,int> m;
        for(auto i:nums1)
            m[i]++;
        for(auto i:nums2)
        {
            if(m.find(i)!=m.end() && m[i]>0)
            {
                res.push_back(i);
                m[i]--;
            }
        }
        return res;
    }
};