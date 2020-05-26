class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        else if(x<=3) return 1;
        int left = 2,right = x/2;
        int mid;
        while(left<right)
        {
            mid = (left+right)/2;
            if(x/mid >= mid && x/(mid+1) < (mid+1))
                return mid;
            else if(x/mid > mid)
                left = mid;
            else right = mid;
        }
        return right;
    }
};