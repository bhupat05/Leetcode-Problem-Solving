// Last updated: 9/12/2026, 6:06:17 PM
1class Solution {
2public:
3    vector<int> maximumWeight(vector<vector<int>>& intervals) {
4        int n = intervals.size();
5        vector<tuple<int, int, int, int>> arr;
6        for (int i = 0; i < n; i++) {
7            int l = intervals[i][0], r = intervals[i][1],
8                weight = intervals[i][2];
9            arr.emplace_back(l, r, weight, i);
10        }
11        sort(arr.begin(), arr.end(),
12             [](auto&& a, auto&& b) { return get<1>(a) < get<1>(b); });
13
14        vector<vector<long long>> dp(n + 1, vector<long long>(5));
15        vector<vector<vector<int>>> indices(n + 1, vector<vector<int>>(5));
16        for (int i = 0; i < n; i++) {
17            auto [l, r, weight, idx] = arr[i];
18            
19            int k = lower_bound(arr.begin(), arr.begin() + i, l,
20                                [](const tuple<int, int, int, int>& t,
21                                   int val) { return get<1>(t) < val; }) -
22                    arr.begin();
23
24            for (int j = 1; j < 5; j++) {
25                long long s1 = dp[i][j];
26                long long s2 = dp[k][j - 1] + weight;
27                if (s1 > s2) {
28                    dp[i + 1][j] = dp[i][j];
29                    indices[i + 1][j] = indices[i][j];
30                    continue;
31                }
32
33                vector<int> newIndex = indices[k][j - 1];
34                newIndex.push_back(idx);
35                sort(newIndex.begin(), newIndex.end());
36                if (s1 == s2 && indices[i][j] < newIndex) {
37                    newIndex = indices[i][j];
38                }
39                dp[i + 1][j] = s2;
40                indices[i + 1][j] = newIndex;
41            }
42        }
43
44        return indices[n][4];
45    }
46};