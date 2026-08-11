// Last updated: 8/11/2026, 9:34:09 AM
1class Solution {
2public:
3    int m, n;
4    bool solve(vector<vector<int>>& pre, int k) {
5        int mxr = INT_MIN;
6        int mxc = INT_MIN;
7
8        int mnr = INT_MAX;
9        int mnc = INT_MAX;
10        int cnt = 0;
11
12        for(int i = 0; i <= m - k; i++) {
13            for(int j = 0; j <= n - k; j++) {
14                int sum = pre[i + k][j + k] - pre[i][j + k] - pre[i + k][j] + pre[i][j];
15
16                if(sum == k * k) {
17                    mxr = max(mxr, i);
18                    mxc = max(mxc, j);
19                    mnr = min(mnr, i);
20                    mnc = min(mnc, j);
21                    cnt++;
22                }
23            }
24        }
25
26        return cnt ? (mxc - mnc >= k) || (mxr - mnr >= k) : false;
27
28
29    }
30    int maxArea(vector<vector<int>>& mat) {
31        m = mat.size();
32        n = mat[0].size();
33        vector<vector<int>> pre(m + 1, vector<int>(n + 1, 0));
34
35        for(int i = 0; i < m; i++) {
36            for(int j = 0; j < n; j++) {
37                pre[i + 1][j + 1] = mat[i][j] + pre[i][j + 1] + pre[i + 1][j] - pre[i][j];
38            }
39        }
40
41        int l = 1;
42        int r = min(m, n);
43        int ans = 0;
44
45        while(l <= r) {
46            int k = l + (r - l) / 2;
47
48            if(solve(pre, k)) {
49                ans = k;
50                l = k + 1;
51            } else {
52                r = k - 1;
53            }
54        }
55        return ans * ans;
56    }
57};