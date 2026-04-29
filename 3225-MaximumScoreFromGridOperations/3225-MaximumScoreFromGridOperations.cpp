// Last updated: 4/29/2026, 8:49:11 AM
1using vll = std::vector<long long>;
2
3class Solution {
4public:
5    long long maximumScore(vector<vector<int>>& grid) {
6        int n = grid[0].size();
7        if (n == 1) {
8            return 0;
9        }
10
11        vector<vector<vll>> dp(n, vector<vll>(n + 1, vll(n + 1, 0)));
12        vector<vll> prevMax(n + 1, vll(n + 1, 0));
13        vector<vll> prevSuffixMax(n + 1, vll(n + 1, 0));
14        vector<vll> colSum(n, vll(n + 1, 0));
15
16        for (int c = 0; c < n; c++) {
17            for (int r = 1; r <= n; r++) {
18                colSum[c][r] = colSum[c][r - 1] + grid[r - 1][c];
19            }
20        }
21
22        for (int i = 1; i < n; i++) {
23            for (int currH = 0; currH <= n; currH++) {
24                for (int prevH = 0; prevH <= n; prevH++) {
25                    if (currH <= prevH) {
26                        long long extraScore =
27                            colSum[i][prevH] - colSum[i][currH];
28                        dp[i][currH][prevH] =
29                            std::max(dp[i][currH][prevH],
30                                     prevSuffixMax[prevH][0] + extraScore);
31                    } else {
32                        long long extraScore =
33                            colSum[i - 1][currH] - colSum[i - 1][prevH];
34                        dp[i][currH][prevH] = std::max(
35                            {dp[i][currH][prevH], prevSuffixMax[prevH][currH],
36                             prevMax[prevH][currH] + extraScore});
37                    }
38                }
39            }
40
41            for (int currH = 0; currH <= n; currH++) {
42                prevMax[currH][0] = dp[i][currH][0];
43                for (int prevH = 1; prevH <= n; prevH++) {
44                    long long penalty =
45                        (prevH > currH) ? (colSum[i][prevH] - colSum[i][currH])
46                                        : 0;
47                    prevMax[currH][prevH] =
48                        std::max(prevMax[currH][prevH - 1],
49                                 dp[i][currH][prevH] - penalty);
50                }
51
52                prevSuffixMax[currH][n] = dp[i][currH][n];
53                for (int prevH = n - 1; prevH >= 0; prevH--) {
54                    prevSuffixMax[currH][prevH] = std::max(
55                        prevSuffixMax[currH][prevH + 1], dp[i][currH][prevH]);
56                }
57            }
58        }
59
60        long long ans = 0;
61        for (int k = 0; k <= n; k++) {
62            ans = std::max({ans, dp[n - 1][n][k], dp[n - 1][0][k]});
63        }
64
65        return ans;
66    }
67};