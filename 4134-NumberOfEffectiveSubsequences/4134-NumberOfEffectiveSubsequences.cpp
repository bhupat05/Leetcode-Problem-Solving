// Last updated: 3/18/2026, 2:19:33 PM
class Solution {
public:
    int countEffective(vector<int>& nums) {
        const int MOD = 1000000007;
        int n = nums.size();

        int S = 0;
        for (int x : nums) S |= x;

        vector<int> bits;
        for (int b = 0; b < 20; b++)
            if (S & (1 << b)) bits.push_back(b);

        int B = bits.size();
        int M = 1 << B;

        vector<int> cnt(M, 0);

        for (int x : nums) {
            int mask = 0;
            for (int i = 0; i < B; i++)
                if (x & (1 << bits[i])) mask |= (1 << i);
            cnt[mask]++;
        }

        // SOS DP: make cnt[mask] = sum of all freq[submask]
        for (int i = 0; i < B; i++) {
            for (int mask = 0; mask < M; mask++) {
                if (mask & (1 << i))
                    cnt[mask] += cnt[mask ^ (1 << i)];
            }
        }

        vector<int> pow2(n+1);
        pow2[0] = 1;
        for (int i = 1; i <= n; i++)
            pow2[i] = (pow2[i-1] * 2LL) % MOD;

        long long ans = 0;

        for (int T = 1; T < M; T++) {
            int comp = (M - 1) ^ T;  // complement of T within B bits
            int safe = cnt[comp];

            long long ways = pow2[safe];
            int bitsCount = __builtin_popcount(T);

            if (bitsCount % 2 == 1) ans += ways;
            else ans -= ways;

            ans %= MOD;
            if (ans < 0) ans += MOD;
        }

        return ans;
    }
};
