class Solution {
public:
    int countPrimes(int n) {
        vector<bool> signs(n,true);
        int count = 0;
        for(int i=2;i<n;i++)
        {
            if(signs[i])
            {
                count++;
                for(int j=i;j<n;j+=i)
                {
                    signs[j] = false;
                }
            }
            
        }
        return count;
    }
};