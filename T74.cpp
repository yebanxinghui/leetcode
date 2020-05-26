class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0,right = m-1;
        int tmp;
        while(left <= right)
        {
            int mid = left+(right-left)/2;
            if(matrix[mid][0] <= target && matrix[mid][n-1]>=target)
            {
                left = mid;
                break;
            }
            else if(matrix[mid][0] > target)
            {
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        if(left<0) tmp = 0;
        else if(left>m-1) tmp = m-1;
        else tmp = left;
        left = 0;
        right = n-1;
        while(left <= right)
        {
            int mid = left+(right-left)/2;
            if(matrix[tmp][mid] == target)
            {
                return true;
            }
            else if(matrix[tmp][mid] > target)
            {
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        return false;
    }
};