class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int num = 0;
        unordered_map<int,int> m1,m2;
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<B.size();j++)
            {
                m1[0-A[i]-B[j]]++;
            }
        }
        for(int i=0;i<C.size();i++)
        {
            for(int j=0;j<D.size();j++)
            {
                if(m1.find(C[i]+D[j])!=m1.end()) num+=m1[C[i]+D[j]];
            }
        }
        return num;
    }
};