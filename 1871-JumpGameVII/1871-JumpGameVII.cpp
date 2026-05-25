// Last updated: 5/25/2026, 8:18:54 PM
1class Solution {
2public:
3    bool canReach(string s, int minJump, int maxJump) {
4        int n = s.size();
5        vector<int> f(n), pre(n);
6        f[0] = 1;
7        
8        for (int i = 0; i < minJump; ++i) {
9            pre[i] = 1;
10        }
11        for (int i = minJump; i < n; ++i) {
12            int left = i - maxJump, right = i - minJump;
13            if (s[i] == '0') {
14                int total = pre[right] - (left <= 0 ? 0 : pre[left - 1]);
15                f[i] = (total != 0);
16            }
17            pre[i] = pre[i - 1] + f[i];
18        }
19        return f[n - 1];
20    }
21};