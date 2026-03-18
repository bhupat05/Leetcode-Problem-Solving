// Last updated: 3/18/2026, 2:20:16 PM
class Solution {
public:
    long long getCost(int len, int k) {
        if (len <= k) return 0;
        if (len % k == 0) {
            int parts = len / k;
            return 1LL * (parts - 1) * k * k;
        }
        int full = len / k;
        int rem = len % k;
        return 1LL * full * rem * k;
    }

    long long minCuttingCost(int n, int m, int k) {
        return getCost(n, k) + getCost(m, k);
    }
};
