// Last updated: 9/17/2026, 3:14:13 PM
1class Solution {
2public:
3    int minSumOfLengths(vector<int>& arr, int target) {
4        int n = arr.size();
5        vector<int> start(n, INT_MAX);
6        vector<int> end(n, INT_MAX);
7
8        int l = 0;
9        int sum = 0;
10        for(int i = 0; i < n; i++) {
11            sum += arr[i];
12            while(l <= i && sum >= target) {
13                if(sum == target) {
14                    start[l] = i - l + 1;
15                    end[i] = i - l + 1;
16                }
17                sum -= arr[l];
18                l++;
19            }
20        }
21        vector<int> pre(n);
22        vector<int> suff(n);
23
24        pre[0] = end[0];
25        for(int i = 1; i < n; i++) {
26            pre[i] = min(end[i], pre[i - 1]);
27        }
28
29        suff[n - 1] = start[n - 1];
30        for(int i = n - 2; i >= 0; i--) {
31            suff[i] = min(suff[i + 1], start[i]);
32        }
33        int ans = INT_MAX;
34
35        for(int i = 1; i < n - 1; i++) {
36            if(pre[i - 1] != INT_MAX && suff[i] != INT_MAX) {
37                ans = min(ans, pre[i - 1] + suff[i]);
38            }
39        }
40        return ans == INT_MAX ? -1 : ans;
41    }
42};