class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;//键位元素，值为频率
        for(int i=0;i<nums.size();i++)
        {
           m[nums[i]]++; 
        }
        int n = m.size();

        //然后就是topk算法
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto iter = m.begin();iter!=m.end();iter++)
        {
            if(k==pq.size() )
            {
                if(iter->second>pq.top().first)
                {
                    pq.pop();
                    pq.push(make_pair(iter->second,iter->first));
                }
                
            }
            else pq.push(make_pair(iter->second,iter->first));
        }

        vector<int> res;
        while(!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
    
};