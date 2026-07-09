// Last updated: 7/9/2026, 9:39:16 AM
1class Solution {
2public:
3    int dx[4] = {1, -1, 0, 0};
4    int dy[4] = {0, 0, 1, -1};
5    void dfs(vector<vector<char>>& board, int i, int j, char c) {
6        int m = board.size();
7        int n = board[0].size();
8
9        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') return;
10
11        board[i][j] = c;
12
13        for(int k = 0; k < 4; k++) {
14            int ni = i + dx[k];
15            int nj = j + dy[k];
16
17            dfs(board, ni, nj, c);
18        }
19    }
20    void solve(vector<vector<char>>& board) {
21        int m = board.size();
22        int n = board[0].size();
23
24        for(int i = 0; i < n; i++) {
25            if(board[0][i] == 'O') dfs(board, 0, i, '#');
26            if(board[m - 1][i] == 'O') dfs(board, m - 1, i, '#');
27        }
28
29        for(int i = 0; i < m; i++) {
30            if(board[i][0] == 'O') dfs(board, i, 0, '#');
31            if(board[i][n - 1] == 'O') dfs(board, i, n - 1, '#');
32        }
33
34        for(int i = 1; i < m; i++) {
35            for(int j = 1; j < n; j++) {
36                if(board[i][j] == 'O') dfs(board, i, j, 'X');
37            }
38        }
39
40        for(int i = 0; i < m; i++) {
41            for(int j = 0; j < n; j++) {
42                if(board[i][j] == '#') board[i][j] = 'O';
43            }
44        }
45
46    }
47};