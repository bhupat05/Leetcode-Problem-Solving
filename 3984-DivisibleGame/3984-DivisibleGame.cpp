// Last updated: 8/15/2026, 1:17:28 PM
1class Solution {
2public:
3    static const int MOD = 1e9 + 7;
4
5    int solve(vector<int>& v) {
6        int curr = v[0];
7        int best = v[0];
8
9        for (int i = 1; i < v.size(); i++) {
10            curr = max(v[i], curr + v[i]);
11            best = max(best, curr);
12        }
13
14        return best;
15    }
16
17    int divisibleGame(vector<int>& nums) {
18        int n = nums.size();
19
20        set<int> candidates;
21        candidates.insert(2);
22
23        for (int x : nums) {
24            if(x > 1)
25            candidates.insert(x);
26
27            for (int d = 2; d * d <= x; d++) {
28                if (x % d == 0) {
29                    candidates.insert(d);
30                    candidates.insert(x / d);
31                }
32            }
33        }
34
35        int maxi = INT_MIN;
36        int k = INT_MAX;
37
38        for (int x : candidates) {
39            vector<int> v = nums;
40
41            for (int j = 0; j < n; j++) {
42                if (v[j] % x != 0) {
43                    v[j] = -v[j];
44                }
45            }
46
47            int sum = solve(v);
48
49            if (sum > maxi || (sum == maxi && x < k)) {
50                maxi = sum;
51                k = x;
52            }
53        }
54
55        long long ans = (1LL * maxi * k) % MOD;
56
57        if (ans < 0) {
58            ans += MOD;
59        }
60
61        return ans;
62    }
63};