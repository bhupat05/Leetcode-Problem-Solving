// Last updated: 9/7/2026, 7:31:02 PM
1class Solution {
2public:
3    int mod = 1e9 + 7;
4    int numberOfUniqueGoodSubsequences(string s) {
5        int n = s.size();
6        int end1 = 0;
7        int end0 = 0;
8        bool f = false;
9        for(int i = 0; i < n; i++) {
10            if(s[i] == '0') {
11                end0 = (end1 + end0) % mod;
12                f = true;
13            } else {
14                end1 = (end1 + end0 + 1) % mod;
15            }
16        }
17        return (end1 + end0 + (f ? 1 : 0)) % mod;
18    }
19};
20
21
22