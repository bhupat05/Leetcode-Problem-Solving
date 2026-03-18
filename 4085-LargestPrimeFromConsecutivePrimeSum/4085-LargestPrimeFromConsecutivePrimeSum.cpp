// Last updated: 3/18/2026, 2:19:44 PM
class Solution {
public:
    int largestPrime(int n) {
        if (n <= 1) return 0;

        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        long long sum = 0;
        int r = 0;

        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                sum += i;
                if (sum > n) break;
                if (isPrime[sum]) r = sum;
            }
        }

        return r;
    }
};
