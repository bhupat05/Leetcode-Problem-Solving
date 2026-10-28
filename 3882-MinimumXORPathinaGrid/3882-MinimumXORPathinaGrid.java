// Last updated: 10/28/2026, 11:13:36 PM
1class Solution {
2    public int minCost(int[][] grid) {
3        int m = grid.length;
4        int n = grid[0].length;
5        Set<Integer>[][] st = new HashSet[m][n];
6        for(int i = 0; i < m; i++) {
7            for(int j = 0; j < n; j++) {
8                st[i][j] = new HashSet<>();
9            }
10        }
11
12        st[0][0].add(grid[0][0]);
13        for(int i = 1; i < n; i++) {
14            for(int x : st[0][i - 1]) {
15                st[0][i].add(x ^ grid[0][i]);
16            }
17        }
18
19        for(int i = 1; i < m; i++) {
20            for(int x : st[i - 1][0]) {
21                st[i][0].add(x ^ grid[i][0]);
22            }
23        }
24
25        for(int i = 1; i < m; i++) {
26            for(int j = 1; j < n; j++) {
27                for(int x : st[i][j - 1]) {
28                    st[i][j].add(x ^ grid[i][j]);
29                }
30
31                for(int x : st[i - 1][j]) {
32                    st[i][j].add(x ^ grid[i][j]);
33                }
34            }
35        }
36        int ans = Integer.MAX_VALUE;
37        for(int x : st[m - 1][n - 1]) {
38            ans = Math.min(ans, x);
39        }
40        return ans;
41    }
42}