class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int len = nums.size();
        for(int j=0;j<nums.size();j++)
        {
            if(nums[j]==val)
            {
                len--;
            }
            else
            {
                nums[i]=nums[j];
                i++;
            }
        }
        return len;
    }
};