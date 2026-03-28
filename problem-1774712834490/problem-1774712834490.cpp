// Last updated: 3/28/2026, 9:17:14 PM
1class Solution {
2public:
3    int mod = 1e9 + 7;
4
5    vector<long long> dp;
6
7    long long fact(int n) {
8        if(dp[n] != -1) return dp[n];
9
10        if(n == 0) return dp[n] = 1;
11
12        return dp[n] = (fact(n - 1) * n) % mod;
13    }
14
15    long long solve(int n, int r) {
16        if(r < 0 || r > n) return 0;
17
18        long long x = fact(n);
19        long long y = (fact(r) * fact(n - r)) % mod;
20
21        long long p = mod - 2, res = 1;
22
23        while(p) {
24            if(p & 1) res = (res * y) % mod;
25            y = (y * y) % mod;
26            p >>= 1;
27        }
28
29        return (x * res) % mod;
30    }
31
32    int countVisiblePeople(int n, int pos, int k) {
33
34        dp.resize(n + 1, -1);
35
36        int l = pos;
37        int r = n - pos - 1;
38
39        long long ans = 0;
40
41        for(int i = 0; i <= k; i++) {
42            ans = (ans + solve(l, i) * solve(r, k - i)) % mod;
43        }
44
45        return (ans * 2) % mod;
46    }
47};