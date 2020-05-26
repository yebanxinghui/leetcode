class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<3) return 0;
        int len = height.size();
        int sum = 0;
        //第一遍，从左往右
        int max = height[0];
        for(int i=0;i<len;i++)
        {
            if(height[i]>max)
                max = height[i];
            sum += max;
            sum -= height[i];
        }
        //第二遍，从右往左
        max = height[len-1];
        for(int i=len-1;i>=0;i--)
        {
            if(height[i]>max)
                max = height[i];
            sum += max;
        }

        //减去最大梯形
        sum -= len * max;
        return sum;
    }
};