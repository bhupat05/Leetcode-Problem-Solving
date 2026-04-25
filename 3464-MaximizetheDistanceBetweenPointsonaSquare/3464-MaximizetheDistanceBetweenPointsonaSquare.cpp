// Last updated: 4/25/2026, 9:16:10 AM
1class Solution {
2public:
3    int maxDistance(int side, vector<vector<int>>& points, int k) {
4
5        auto flatten = [&](vector<int>& p) -> long long {
6            long long x = p[0], y = p[1];
7            if (y == 0) return x;
8            if (x == side) return side + y;
9            if (y == side) return 3LL * side - x;
10            return 4LL * side - y;
11        };
12
13        vector<long long> arr;
14        for (auto &p : points) arr.push_back(flatten(p));
15        sort(arr.begin(), arr.end());
16
17        int n = arr.size();
18
19        auto notValid = [&](long long d) {
20            for (int i = 0; i < n; i++) {
21                int ptr = i, cnt = 1;
22
23                while (cnt < k) {
24                    long long target = arr[ptr] + d;
25                    int j = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
26
27                    if (j == n) break;
28
29                    ptr = j;
30                    cnt++;
31
32                    if (d + arr[ptr] > arr[i] + 4LL * side) {
33                        cnt = 0;
34                        break;
35                    }
36                }
37
38                if (cnt == k) return false;
39            }
40            return true;
41        };
42
43        long long low = 0, high = side, ans = 0;
44
45        while (low <= high) {
46            long long mid = (low + high) / 2;
47
48            if (!notValid(mid)) {
49                ans = mid;
50                low = mid + 1;
51            } else {
52                high = mid - 1;
53            }
54        }
55
56        return (int)ans;
57    }
58};