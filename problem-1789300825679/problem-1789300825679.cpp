// Last updated: 9/13/2026, 5:30:25 PM
1class Solution {
2public:
3    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
4        for(int i = 0; i < n; i++) {
5            reverse(grid[i].begin(), grid[i].begin() + rowShift[i]);
6            reverse(grid[i].begin() + rowShift[i], grid[i].end() );
7            reverse(grid[i].begin(), grid[i].end());
8        }
9        for(int i = 0; i < n; i++) {
10            vector<int> v;
11            for(int j = 0; j < n; j++) {
12                v.push_back(grid[j][i]);
13            }
14
15            reverse(v.begin(), v.begin() + colShift[i]);
16            reverse(v.begin() + colShift[i],v.end() );
17            reverse(v.begin(), v.end());
18            for(int j = 0; j < n; j++) {
19                grid[j][i] = v[j];
20            }
21        }
22        return grid;
23    }
24};