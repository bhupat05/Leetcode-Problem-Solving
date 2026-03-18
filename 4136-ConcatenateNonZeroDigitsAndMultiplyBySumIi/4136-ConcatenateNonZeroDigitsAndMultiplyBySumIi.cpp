// Last updated: 3/18/2026, 2:19:31 PM
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long MOD = 1000000007;
        int n = s.size();

        vector<long long> prefixSum(n);
        vector<long long> prefixCount(n);
        vector<long long> prefixVal(n);
        vector<long long> pow10(n + 1);

        pow10[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10LL) % MOD;
        }

        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';

            if (i > 0) {
                prefixVal[i] = prefixVal[i - 1];
                prefixSum[i] = prefixSum[i - 1];
                prefixCount[i] = prefixCount[i - 1];
            }

            if (d != 0) {
                prefixVal[i] = (prefixVal[i] * 10LL + d) % MOD;
                prefixSum[i] += d;
                prefixCount[i] += 1;
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            long long cnt = prefixCount[r] - (l > 0 ? prefixCount[l - 1] : 0);
            long long sum = prefixSum[r] - (l > 0 ? prefixSum[l - 1] : 0);

            if (cnt == 0) {
                ans.push_back(0);
                continue;
            }

            long long x = prefixVal[r];
            if (l > 0) {
                long long removePart = (prefixVal[l - 1] * pow10[cnt]) % MOD;
                x = (x - removePart + MOD) % MOD;
            }

            long long result = (x * sum) % MOD;
            ans.push_back((int)result);
        }

        return ans;
    }
};
