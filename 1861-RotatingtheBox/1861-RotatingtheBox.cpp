// Last updated: 5/6/2026, 8:23:02 AM
1class Solution {
2public:
3    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
4        int m = boxGrid.size();
5        int n = boxGrid[0].size();
6
7        vector<vector<char>> result(n, vector<char>(m, '.'));
8
9        for(int i = 0; i < m; i++) {
10            int l = n - 1;
11
12            for(int j = n - 1; j >= 0; j--) {
13
14                if(boxGrid[i][j] == '#') {
15                    swap(boxGrid[i][j], boxGrid[i][l]);
16                    l--;
17                }
18
19                else if(boxGrid[i][j] == '*') {
20                    l = j - 1;
21                }
22            }
23        }
24
25        for(int i = 0; i < m; i++) {
26            for(int j = 0; j < n; j++) {
27                result[j][m - 1 - i] = boxGrid[i][j];
28            }
29        }
30
31        return result;
32    }
33};