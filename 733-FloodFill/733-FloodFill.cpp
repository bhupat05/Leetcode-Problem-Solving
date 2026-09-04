// Last updated: 9/4/2026, 3:01:37 PM
1class Solution {
2public:
3    int m, n;
4    int dx[4] = {1, -1, 0, 0};
5    int dy[4] = {0, 0, 1, -1};
6    void dfs(vector<vector<int>>& image, int i, int j, int x, int color) {
7
8        if(i < 0 || j < 0 || i >= m || j >= n || image[i][j] != x || image[i][j] == color) return;
9
10        image[i][j] = color;
11        for(int d = 0; d < 4; d++) {
12            dfs(image, i + dx[d], j + dy[d], x, color);
13        }
14    }
15    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
16        m = image.size();
17        n = image[0].size();
18        dfs(image, sr, sc, image[sr][sc], color);
19        return image;
20    }
21};