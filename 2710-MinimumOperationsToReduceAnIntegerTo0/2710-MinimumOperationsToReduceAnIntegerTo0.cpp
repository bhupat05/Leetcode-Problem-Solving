// Last updated: 3/18/2026, 2:22:17 PM
class Solution {
public:
    int minOperations(int n) {
        int ops = 0;

        while (n > 0) {
            int lowbit = n & -n;

            if (n & (lowbit << 1))
                n += lowbit;
            else
                n -= lowbit;

            ops++;
        }

        return ops;
    }
};