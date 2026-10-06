// Last updated: 10/6/2026, 9:30:25 AM
1class Solution {
2public:
3    int minAddToMakeValid(string s) {
4        int ans = 0;
5        int cnt = 0;
6
7        for(char c : s) {
8            if(c == '(') {
9                cnt++;
10            } else {
11                if(cnt == 0) {
12                    ans++;
13                } else {
14                    cnt--;
15                }
16            }
17        }
18        cnt = 0;
19
20        for(int i = s.size() - 1; i >= 0; i--) {
21            if(s[i] == ')') {
22                cnt++;
23            } else {
24                if(cnt == 0) {
25                    ans++;
26                } else {
27                    cnt--;
28                }
29            }
30        }
31        return ans;
32    }
33};