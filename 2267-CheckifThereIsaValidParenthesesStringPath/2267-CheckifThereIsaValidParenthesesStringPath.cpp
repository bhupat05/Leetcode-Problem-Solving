// Last updated: 9/29/2026, 3:07:36 PM
1class Solution {
2public:
3    int m, n;
4
5    int dx[2] = {1, 0};
6    int dy[2] = {0, 1};
7    vector<vector<vector<int>>> dp;
8
9    bool solve(vector<vector<char>>& grid, int i, int j, int cnt) {
10        if (i < 0 || j < 0 || i >= m || j >= n) {
11            return false;
12        }
13
14        if (cnt < 0) {
15            return false;
16        }
17
18        if (grid[i][j] == '(') {
19            cnt++;
20        } else {
21            cnt--;
22        }
23
24        if (cnt < 0) {
25            return false;
26        }
27
28        if (i == m - 1 && j == n - 1) {
29            return cnt == 0;
30        }
31
32        if (dp[i][j][cnt] != -1) {
33            return dp[i][j][cnt];
34        }
35
36        for (int d = 0; d < 2; d++) {
37            int ni = i + dx[d];
38            int nj = j + dy[d];
39
40            if (solve(grid, ni, nj, cnt)) {
41                return dp[i][j][cnt] = 1;
42            }
43        }
44
45        return dp[i][j][cnt] = 0;
46    }
47
48    bool hasValidPath(vector<vector<char>>& grid) {
49        m = grid.size();
50        n = grid[0].size();
51
52        dp.assign(
53            m,
54            vector<vector<int>>(
55                n,
56                vector<int>(m + n + 1, -1)
57            )
58        );
59
60        return solve(grid, 0, 0, 0);
61    }
62};