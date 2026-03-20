// Last updated: 3/20/2026, 9:40:10 AM
1class Solution {
2public:
3    int solve(vector<vector<int>>& grid, int l, int r, int k) {
4        int m = grid.size();
5        int n = grid[0].size();
6        vector<int> v;
7        for(int i = l; i < l + k; i++) {
8            for(int j = r; j < r + k; j++) {
9                // if(i < m && j < n)
10                v.push_back(grid[i][j]);
11            }
12        }
13        int diff = 0;
14
15        if(v.size() == 1) return 0;
16         for(int i = 0; i < v.size(); i++) {
17            for(int j = i + 1; j < v.size(); j++) {
18                if(v[i] != v[j]) {
19                    diff = abs(v[i] - v[j]);
20                    break;
21                }
22            }
23        }
24
25        for(int i = 0; i < v.size(); i++) {
26            for(int j = i + 1; j < v.size(); j++) {
27                if(v[i] != v[j]) {
28                    diff = min(diff, abs(v[i] - v[j]));
29                }
30            }
31        }
32        return diff;
33    }
34    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
35        int m = grid.size();
36        int n = grid[0].size();
37        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));
38
39        for(int i = 0; i < m; i++) {
40            for(int j = 0; j < n; j++) {
41                if(i + k <= m && j + k <= n) {
42                    int x = solve(grid, i, j, k);
43                    ans[i][j] = x;
44                }
45                
46            }
47        }
48        return ans;
49    }
50};