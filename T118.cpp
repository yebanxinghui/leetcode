class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows,vector<int>(1,1));
        if(numRows == 0) return res;
        
        for(int i=1;i<numRows;i++)
        {

            for(int j=0;j<i-1;j++)
            {
                res[i].push_back(res[i-1][j]+res[i-1][j+1]);
            }
            res[i].push_back(1);
            
        }
        return res;
    }
};