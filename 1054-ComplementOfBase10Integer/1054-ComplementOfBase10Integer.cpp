// Last updated: 3/18/2026, 2:25:33 PM
class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int m = 0;
        int temp = n;

        while(temp > 0) {
            m = (m << 1) | 1;
            temp >>= 1;
        }

        return n ^ m;
    }
};