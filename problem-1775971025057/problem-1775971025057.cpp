// Last updated: 4/12/2026, 10:47:05 AM
1class Solution {
2public:
3    int countNegatives(vector<vector<int>>& grid) {
4        int m = grid.size();
5        int n = grid[0].size();
6        int i = 0;
7        int j = n - 1;
8        int ans = 0;
9
10        while(i < m && j >= 0) {
11            if(grid[i][j] < 0) {
12                ans += (m - i);
13                j--;
14            } else {
15                i++;
16            }
17        }
18        return ans;
19    }
20};