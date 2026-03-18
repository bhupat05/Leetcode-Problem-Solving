// Last updated: 3/18/2026, 2:29:22 PM
class Solution {
public:
    int reverseBits(int n) {
        uint32_t x = n;     
        uint32_t y = 0;

        for (int i = 0; i < 32; i++) {
            y <<= 1;
            y |= (x & 1);
            x >>= 1;
        }

        return y;
    }
};
