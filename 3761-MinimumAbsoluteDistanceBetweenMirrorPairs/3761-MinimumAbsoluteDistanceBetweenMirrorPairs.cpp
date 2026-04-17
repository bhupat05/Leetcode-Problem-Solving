// Last updated: 4/17/2026, 10:23:13 AM
1class Solution {
2public:
3    int rev(int x) {
4        int r = 0;
5        while (x > 0) {
6            r = r * 10 + x % 10;
7            x /= 10;
8        }
9        return r;
10    }
11
12    int minMirrorPairDistance(vector<int>& nums) {
13        unordered_map<int, int> mp;  
14        int ans = INT_MAX;
15        int n = nums.size();
16
17        for (int i = n - 1; i >= 0; i--) {
18            int r = rev(nums[i]);
19
20            if (mp.count(r)) {
21                ans = min(ans, mp[r] - i);
22            }
23
24            mp[nums[i]] = i;
25        }
26
27        return ans == INT_MAX ? -1 : ans;
28    }
29};
30