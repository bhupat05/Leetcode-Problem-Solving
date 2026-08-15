// Last updated: 8/15/2026, 8:37:20 PM
1class Solution {
2public:
3    int solve(string t) {
4        int l = 0;
5        int r = t.size() - 1;
6        int ans = 0;
7
8        while(l < r) {
9            if(t[l] != t[r]) {
10                int a = 26;
11                if(t[r] < t[l]) {
12                    a = t[l] - t[r]; 
13                } else {
14                    a = 'z' - t[r] + (t[l] - 'a') + 1;
15                }
16                int b = 26;
17                if(t[l] < t[r]) {
18                    b = t[r] - t[l]; 
19                } else {
20                    b = 'z' - t[l] + (t[r] - 'a') + 1;
21                }
22                ans += min(a, b);
23            }
24
25            l++;
26            r--;
27        }
28        return ans;
29    }
30    int minOperations(string s) {
31        int n = s.size();
32        
33        int ans = INT_MAX;
34
35        for(int i = 0; i < n; i++) {
36            string t = s;
37            int cnt = 0;
38            reverse(t.begin(), t.begin() + i);
39            reverse(t.begin() + i, t.end());
40            reverse(t.begin(), t.end());
41            cnt = (i + solve(t));
42            ans = min(ans, cnt);
43        }
44        return ans;
45    }
46};