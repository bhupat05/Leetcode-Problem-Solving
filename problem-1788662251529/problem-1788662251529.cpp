// Last updated: 9/6/2026, 8:07:31 AM
1class Solution {
2public:
3    int countRotations(string s, int k) {
4        int cnt = 0;
5        int n = s.size();
6
7        for(int i = 0; i  < n; i++) {
8            string t = s;
9            reverse(t.begin(), t.begin() + i);
10            reverse(t.begin() + i, t.end());
11            reverse(t.begin(), t.end());
12            int score = 0;
13
14            for(int j = 0; j < n - 1; j++) {
15                
16                if(t[j] == t[j + 1]) {
17                    score++;
18                }
19                
20            }
21            if(score == k) cnt++;
22            
23        }
24        return cnt;
25    }
26};