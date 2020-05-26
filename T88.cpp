class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int tail = m+n-1;
        int tail1 = m-1,tail2 = n-1;
        while(tail!=tail1)
        {
            if(tail1 >= 0 && nums1[tail1]>nums2[tail2])
            {
                nums1[tail] = nums1[tail1];
                tail--;
                tail1--;
            }
            else{
                nums1[tail] = nums2[tail2];
                tail--;
                tail2--;
            }
        }
    }
};