class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),back_inserter(nums3));
        int num = nums3.size();
        double x;
        if(num % 2) x =  nums3[(num-1)/2]*1.0;
        else x =  (nums3[num/2]+nums3[num/2-1])*1.0/2;
        return x;
    }
};