class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        set<int> row,col;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == 0)
                {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        set<int>::iterator it;
        for(int i=0;i<n;i++)
            for(it = row.begin();it!=row.end();it++)
                matrix[*it][i] = 0;
        for(int i=0;i<m;i++)
            for(it = col.begin();it!=col.end();it++)
                matrix[i][*it] = 0;
    }
};