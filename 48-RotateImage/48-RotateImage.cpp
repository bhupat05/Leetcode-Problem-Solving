// Last updated: 5/4/2026, 8:23:33 AM
1class Solution {
2public:
3    void rotate(vector<vector<int>>& matrix) {
4        int m = matrix.size();
5        int n = matrix[0].size();
6
7        for(int i = 0; i < m; i++) {
8            for(int j = i; j < n; j++) {
9                swap(matrix[i][j], matrix[j][i]);
10            }
11        }
12
13        for(int i = 0; i < m; i++) {
14            reverse(matrix[i].begin(), matrix[i].end());
15        }
16    }
17};