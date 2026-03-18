// Last updated: 3/18/2026, 2:24:33 PM
class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1000000007;

        long long aba = 6;
        long long abc = 6;

        for (int row = 2; row <= n; row++) {
            long long nextaba = (2 * aba + 2 * abc) % MOD;

            long long nextabc = (2 * aba + 3 * abc) % MOD;

            aba = nextaba;
            abc = nextabc;
        }

        return (aba + abc) % MOD;
    }
};
