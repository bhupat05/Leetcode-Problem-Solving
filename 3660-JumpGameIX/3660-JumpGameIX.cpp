// Last updated: 5/7/2026, 10:49:37 AM
1class Solution {
2public:
3    vector<int> maxValue(vector<int>& nums) {
4        int n = nums.size();
5
6        vector<int> pre(n), suf(n), res(n);
7
8        pre[0] = nums[0];
9        for (int i = 1; i < n; i++) {
10            pre[i] = max(pre[i - 1], nums[i]);
11        }
12
13        suf[n - 1] = nums[n - 1];
14        for (int i = n - 2; i >= 0; i--) {
15            suf[i] = min(suf[i + 1], nums[i]);
16        }
17
18        res[n - 1] = pre[n - 1];
19
20        for (int i = n - 2; i >= 0; i--) {
21
22            if (pre[i] > suf[i + 1]) {
23                res[i] = res[i + 1];
24            }
25
26            else {
27                res[i] = pre[i];
28            }
29        }
30
31        return res;
32    }
33};