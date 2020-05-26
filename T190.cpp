class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans = 0;
        for (int bitsSize = 31; n != 0; n = n >> 1, bitsSize--) {
            ans |= (n & 1) << bitsSize;
        }
        return ans;
    }
};