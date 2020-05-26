class Solution {
public:
    int titleToNumber(string s) {
        long long sum = 0;
        for(auto ch:s)
        {
            sum = sum*26 + (ch-'A'+1);
        }
        return sum;
    }
};