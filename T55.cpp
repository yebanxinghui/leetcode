class Solution {
public:
    bool canJump(vector<int>& nums) {
        int k = 0;
	    for (int i = 0; i < nums.size(); i++)
	    {
	    	if(i > k) return false;
            if(k>=nums.size()-1) return true;
	    	k = max(k, i + nums[i]);
	    }
	    return true;
    }
};