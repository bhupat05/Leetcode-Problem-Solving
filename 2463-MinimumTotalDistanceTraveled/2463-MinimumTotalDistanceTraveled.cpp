// Last updated: 4/14/2026, 8:56:11 AM
1class Solution {
2public:
3    long long dp[101][101][101]; 
4
5    long long solve(vector<int>& robot, vector<vector<int>>& factory, int i, int j, int used) {
6        if (i >= robot.size()) return 0;
7        if (j >= factory.size()) return 1e15;
8
9        if (dp[i][j][used] != -1) return dp[i][j][used];
10
11        long long res = 1e15;
12
13        if (used < factory[j][1]) {
14            long long a = abs(robot[i] - factory[j][0]) +
15                             solve(robot, factory, i + 1, j, used + 1);
16            res = min(res, a);
17        }
18
19        long long b = solve(robot, factory, i, j + 1, 0);
20        res = min(res, b);
21
22        return dp[i][j][used] = res;
23    }
24
25    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
26        sort(robot.begin(), robot.end());
27        sort(factory.begin(), factory.end());
28
29        memset(dp, -1, sizeof(dp));
30
31        return solve(robot, factory, 0, 0, 0);
32    }
33};