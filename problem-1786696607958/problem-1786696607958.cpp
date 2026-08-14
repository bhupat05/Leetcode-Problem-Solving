// Last updated: 8/14/2026, 2:06:47 PM
1class Solution {
2public:
3    int maxDigitRange(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> r(n, 0);
6        int mx = INT_MIN;
7
8        for(int i = 0; i < n; i++) {
9            int mini = INT_MAX;
10            int maxi = INT_MIN;
11            int x = nums[i];
12            while(x > 0) {
13                mini = min(mini, x % 10);
14                maxi = max(maxi, x % 10);
15                x /= 10;
16            }
17            r[i] = maxi - mini;
18            mx = max(mx, r[i]);
19        }
20        int ans = 0;
21        for(int i = 0; i < n; i++) {
22            if(r[i] == mx) {
23                ans += nums[i];
24            }
25        }
26        return ans;
27    }
28};