// Last updated: 7/9/2026, 9:43:35 AM
1class Solution {
2public:
3    int dir[5] = {0, 1, 0, -1, 0};
4
5    void dfs(vector<vector<char>>& board, int i, int j) {
6        int m = board.size(), n = board[0].size();
7
8        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O')
9            return;
10
11        board[i][j] = '#';
12
13        for (int k = 0; k < 4; k++)
14            dfs(board, i + dir[k], j + dir[k + 1]);
15    }
16
17    void solve(vector<vector<char>>& board) {
18        int m = board.size(), n = board[0].size();
19
20        for (int j = 0; j < n; j++) {
21            dfs(board, 0, j);
22            dfs(board, m - 1, j);
23        }
24
25        for (int i = 0; i < m; i++) {
26            dfs(board, i, 0);
27            dfs(board, i, n - 1);
28        }
29
30        for (int i = 0; i < m; i++) {
31            for (int j = 0; j < n; j++) {
32                if (board[i][j] == 'O')
33                    board[i][j] = 'X';
34                else if (board[i][j] == '#')
35                    board[i][j] = 'O';
36            }
37        }
38    }
39};