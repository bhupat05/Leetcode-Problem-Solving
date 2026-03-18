// Last updated: 3/18/2026, 2:21:45 PM
class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const int MOD = 1e9 + 7;

        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<long long> hDiffs;

        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                hDiffs.insert(hFences[j] - hFences[i]);
            }
        }

        long long maxSide = 0;

        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                long long d = vFences[j] - vFences[i];
                if (hDiffs.count(d)) {
                    maxSide = max(maxSide, d);
                }
            }
        }

        if (maxSide == 0) return -1;

        return (maxSide % MOD) * (maxSide % MOD) % MOD;
    }
};
