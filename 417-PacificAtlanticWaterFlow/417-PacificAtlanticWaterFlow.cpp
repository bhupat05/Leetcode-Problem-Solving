// Last updated: 7/9/2026, 8:56:44 AM
1class Solution {
2public:
3    int dx[4] = {1, -1, 0, 0};
4    int dy[4] = {0, 0, 1, -1};
5    bool dfs(vector<vector<int>>& heights, int i, int j, int ti, int tj, set<pair<int, int>>& s) {
6        int m = heights.size();
7        int n = heights[0].size();
8
9        if(i == ti || j == tj) return true;
10        if(i < 0 || i >= m || j < 0 || j >= n || s.count({i, j})) return false;
11
12        s.insert({i, j});
13
14       
15
16        for(int k = 0; k < 4; k++) {
17            int ni = i + dx[k];
18            int nj = j + dy[k];
19
20            if(ni >= 0 && ni < m && nj >= 0 && nj < n && heights[ni][nj] > heights[i][j]) continue;
21
22            if(dfs(heights, ni, nj, ti, tj, s)) return true;
23        }
24
25
26
27        return false;
28    }
29    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
30        int m = heights.size();
31        int n = heights[0].size();
32        vector<vector<int>> r;
33
34        for(int i = 0; i < m; i++) {
35            for(int j = 0; j < n; j++) {
36                set<pair<int, int>> s1;
37                set<pair<int, int>> s2;
38                if(dfs(heights, i, j, 0, 0, s1) && dfs(heights, i, j, m - 1, n - 1, s2)) {
39                    r.push_back({i, j});
40                }
41            }
42        }
43        return r;
44    }
45};