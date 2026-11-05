// Last updated: 11/5/2026, 10:03:07 PM
1class Solution {
2    public boolean isValidSudoku(char[][] board) {
3        Set<Integer>[] rows = new HashSet[9];
4        Set<Integer>[] cols = new HashSet[9];
5        Set<Integer>[] box = new HashSet[9];
6        for(int i = 0; i < 9; i++) {
7            rows[i] = new HashSet<>();
8            cols[i] = new HashSet<>();
9            box[i] = new HashSet<>();
10        }
11        for(int i = 0; i < 9; i++) {
12            for(int j = 0; j < 9; j++) {
13                if(board[i][j] == '.') continue;
14                int x = board[i][j] - '0';
15                int idx = i / 3 + 3 * (j / 3);
16                if(rows[i].contains(x) || cols[j].contains(x) || box[idx].contains(x)) {
17                    return false;
18                }
19                rows[i].add(x);
20                cols[j].add(x);
21                box[idx].add(x);
22            }
23        }
24        return true;
25    }
26}