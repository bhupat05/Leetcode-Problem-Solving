// Last updated: 10/6/2026, 9:32:28 AM
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
18        return ans + cnt;
19    }
20};