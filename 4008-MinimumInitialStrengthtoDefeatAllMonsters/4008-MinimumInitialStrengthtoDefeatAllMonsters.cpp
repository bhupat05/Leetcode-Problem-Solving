// Last updated: 8/7/2026, 11:22:21 AM
1class Solution {
2public:
3    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
4        int n = monsters.size();
5
6        vector<long long> diff(n + 1, 0);
7
8        for (auto &b : boosts) {
9            diff[b[0]] += b[2];
10            if (b[1] + 1 < n)
11                diff[b[1] + 1] -= b[2];
12        }
13
14        vector<long long> bonus(n);
15        bonus[0] = diff[0];
16        for (int i = 1; i < n; i++)
17            bonus[i] = bonus[i - 1] + diff[i];
18
19        long long need = 0;
20
21        for (int i = n - 1; i >= 0; i--) {
22            if (need == 0) {
23                need = max(0LL, 1LL * monsters[i] - bonus[i]);
24            } else {
25                need += monsters[i];
26            }
27        }
28
29        return need;
30    }
31};