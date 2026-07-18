// Last updated: 7/18/2026, 11:34:22 AM
1class Solution {
2public:
3    long long maximumImportance(int n, vector<vector<int>>& roads) {
4        vector<long long> degree(n, 0);
5
6        for (auto &e : roads) {
7            degree[e[0]]++;
8            degree[e[1]]++;
9        }
10
11        sort(degree.begin(), degree.end());
12
13        long long ans = 0;
14        for (int i = 0; i < n; i++)
15            ans += degree[i] * (i + 1);
16
17        return ans;
18    }
19};