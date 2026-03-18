// Last updated: 3/18/2026, 3:01:29 PM
class Solution {
public:
    long long catalan(int n) {
        long long res = 1;

        // Calculate C(2n, n) step by step
        for (int i = 1; i <= n; i++) {
            res = res * (n + i) / i;
        }

        // Catalan number = C(2n, n) / (n + 1)
        return res / (n + 1);
    }

    int numTrees(int n) {
        return (int)catalan(n);
    }
};
