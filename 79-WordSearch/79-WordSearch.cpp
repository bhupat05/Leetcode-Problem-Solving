// Last updated: 7/10/2026, 10:27:08 AM
1class Solution {
2public:
3    int m, n;
4    int dx[5] = {0, 1, 0, -1, 0};
5
6    bool solve(vector<vector<char>>& board, const string& word,
7               int i, int j, int idx) {
8
9        if (idx == word.size())
10            return true;
11
12        if (i < 0 || i >= m || j < 0 || j >= n ||
13            board[i][j] == '#' || board[i][j] != word[idx])
14            return false;
15
16        char temp = board[i][j];
17        board[i][j] = '#';
18
19        for (int k = 0; k < 4; k++) {
20            int ni = i + dx[k];
21            int nj = j + dx[k + 1];
22
23            if (solve(board, word, ni, nj, idx + 1)) {
24                board[i][j] = temp;   
25                return true;
26            }
27        }
28
29        board[i][j] = temp;           
30        return false;
31    }
32
33    bool exist(vector<vector<char>>& board, string word) {
34        m = board.size();
35        n = board[0].size();
36
37        for (int i = 0; i < m; i++) {
38            for (int j = 0; j < n; j++) {
39                if (solve(board, word, i, j, 0))
40                    return true;
41            }
42        }
43
44        return false;
45    }
46};