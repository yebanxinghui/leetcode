class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        if(len<2) return;
        int zero = 0;
        int two = len-1;
        while(zero<=len-1 && nums[zero]==0) zero++;
        while(two>= 0 && nums[two]==2) two--;
        int i = zero;
        while(i <= two)
        {
            if(nums[i] == 0)
            {
                swap(nums[zero],nums[i]);
                zero++;
                i++;
            }
            else if(nums[i]==1)
            {
                i++;
            }
            else{
                swap(nums[i],nums[two]);
                two--;
            }
        }
    }
};