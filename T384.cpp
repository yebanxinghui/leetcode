class Solution {
private:
    vector<int> res;
public:
    Solution(vector<int>& nums) {
        res = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return res;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> vshuf = res;
        for(int i=1;i<vshuf.size();i++)
        {
            int r = rand() % (i+1);
            if(r != i)
                swap(vshuf[i],vshuf[r]);
        }
        return vshuf;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */