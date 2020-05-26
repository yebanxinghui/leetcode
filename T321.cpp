class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res(k,0);
        int m = nums1.size();
        int n = nums2.size();
        int start = max(0,k-m);
        int end = min(k,n);
        for(int i=start;i<=end;i++)
        {
            vector<int> tmp;
            vector<int> tmp1 = maxSeq(nums1, k-i);
            vector<int> tmp2 = maxSeq(nums2, i);
            auto iter1 = tmp1.begin(), iter2 = tmp2.begin();
            while (iter1 != tmp1.end() || iter2 != tmp2.end()){
                tmp.push_back(lexicographical_compare(iter1, tmp1.end(), iter2, tmp2.end()) ? *iter2++ : *iter1++);
            }
            res = lexicographical_compare(res.begin(),res.end(),tmp.begin(),tmp.end()) ? tmp : res;
        }
        return res;
    }
    vector<int> maxSeq(vector<int> v, int k)
    {
        int n = v.size();
        if(n <= k) return v;
        vector<int> res;
        int numOfPop = n-k;
        for(int i=0;i<n;i++)
        {
            while(!res.empty() && v[i] > res.back() && numOfPop-- > 0)
                res.pop_back();
            res.push_back(v[i]);
        }
        res.resize(k);
        return res;
    }
};