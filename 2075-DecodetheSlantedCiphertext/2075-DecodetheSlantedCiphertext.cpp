// Last updated: 4/4/2026, 9:27:49 AM
1class Solution {
2public:
3    string decodeCiphertext(string s, int rows) {
4        int n = s.size();
5        int m = rows;
6        n = n / m;
7        vector<vector<char>> v(m, vector<char>(n));
8        int l = 0;
9        for (int i = 0; i < m; i++) {
10            for (int j = 0; j < n; j++) {
11                v[i][j] = s[l];
12                l++;
13            }
14        }
15        string result = "";
16        for (int i = 0; i < n; i++) {
17            l = 0;
18            int r = i;
19
20            while (l < m && r < n) {
21                result += v[l][r];
22                l++;
23                r++;
24            }
25        }
26        cout << result << " ";
27        int r = result.size() - 1;
28        while(r >= 0 && result[r] == ' ') {
29            r--;
30        }
31        return result.substr(0, r + 1);
32    }
33};