// Last updated: 11/17/2026, 12:54:09 AM
1class Solution {
2public:
3    string digitSum(string s, int k) {
4        while (s.size() > k) {
5            string t = "";
6            int i = 0;
7
8            for (i = 0; i + k <= s.size(); i += k) {
9                int x = 0;
10
11                for (int j = i; j < i + k; j++) {
12                    x += s[j] - '0';
13                }
14
15                t += to_string(x);
16            }
17
18            int x = 0;
19
20            while (i < s.size()) {
21                x += s[i] - '0';
22                i++;
23            }
24
25            if (s.size() % k != 0) {
26                t += to_string(x);
27            }
28
29            s = t;
30        }
31
32        return s;
33    }
34};