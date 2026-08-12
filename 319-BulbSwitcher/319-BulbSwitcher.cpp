// Last updated: 8/13/2026, 12:04:57 AM
1class Solution {
2public:
3    int bulbSwitch(int n) {
4        if(n == 0) return 0;
5
6        int cnt = 0;
7        int x = 1;
8        
9
10        for(int i = 1; i * i <= n; i++) {
11            cnt++;
12        }
13        return cnt;
14    }
15};