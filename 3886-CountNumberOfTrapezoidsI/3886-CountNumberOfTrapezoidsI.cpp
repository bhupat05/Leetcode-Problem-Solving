// Last updated: 3/18/2026, 2:20:13 PM
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const long long MOD = 1000000007;

        unordered_map<int, long long> mp;
        for (auto &p : points) {
            mp[p[1]]++;              
        }

        vector<long long> vals;
        vals.reserve(mp.size());

        for (auto &entry : mp) {
            long long c = entry.second;
            if (c >= 2) {
                long long comb = (c * (c - 1) / 2) % MOD;
                vals.push_back(comb);
            }
        }

        if (vals.size() < 2) return 0;  

        long long ans = 0;
        long long sum = 0;

        for (long long v : vals) {
            ans = (ans + (sum * v) % MOD) % MOD;
            sum = (sum + v) % MOD;
        }

        return ans;
    }
};
