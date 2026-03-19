// Last updated: 3/19/2026, 8:01:45 AM
1class Solution {
2public:
3    int numberOfSubmatrices(vector<vector<char>>& grid) {
4        int m = grid.size();
5        int n = grid[0].size();
6
7        vector<vector<int>> dp1(m, vector<int>(n, 0));
8        vector<vector<int>> dp2(m, vector<int>(n, 0));
9
10        dp1[0][0] = (grid[0][0] == 'X' ? 1 : 0);
11        dp2[0][0] = (grid[0][0] == 'Y' ? 1 : 0);
12        int cnt = 0;
13
14        for(int i = 1; i < n; i++) {
15            dp1[0][i] = dp1[0][i - 1] + (grid[0][i] == 'X' ? 1 : 0);
16            dp2[0][i] = dp2[0][i - 1] + (grid[0][i] == 'Y' ? 1 : 0);
17            if(dp1[0][i] != 0 && dp1[0][i] == dp2[0][i]) cnt++;
18        }
19
20        for(int i = 1; i < m; i++) {
21            dp1[i][0] = dp1[i - 1][0] + (grid[i][0] == 'X' ? 1 : 0);
22            dp2[i][0] = dp2[i - 1][0] + (grid[i][0] == 'Y' ? 1 : 0);
23            if(dp1[i][0] != 0 && dp1[i][0] == dp2[i][0]) cnt++;
24        }
25
26        
27
28        for(int i = 1; i < m; i++) {
29            for(int j = 1; j < n; j++) {
30                dp1[i][j] = dp1[i - 1][j] + dp1[i][j - 1] + (grid[i][j] == 'X' ? 1 : 0) - dp1[i - 1][j - 1];
31                dp2[i][j] = dp2[i - 1][j] + dp2[i][j - 1] + (grid[i][j] == 'Y' ? 1 : 0) - dp2[i - 1][j - 1];
32
33                if(dp1[i][j] != 0 && dp1[i][j] == dp2[i][j]) cnt++;
34            }
35        }
36        return cnt;
37    }
38};