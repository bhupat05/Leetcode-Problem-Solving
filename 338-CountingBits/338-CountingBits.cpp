// Last updated: 6/21/2026, 3:47:59 PM
1class Solution {
2public:
3    vector<int> countBits(int n) {
4        vector<int> r;
5
6        for (int i = 0; i <= n; i++) {
7            int num = i;
8            int x = 0;
9
10            while (num > 0) {
11                x += (num & 1); 
12                num /= 2;       
13            }
14
15            r.push_back(x);
16        }
17
18        return r;
19    }
20};