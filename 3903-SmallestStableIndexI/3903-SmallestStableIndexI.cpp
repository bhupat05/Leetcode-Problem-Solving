// Last updated: 9/4/2026, 9:25:49 AM
1class Solution {
2public:
3    int firstStableIndex(vector<int>& nums, int k) {
4        int n = nums.size();
5        int ans = -1;
6        vector<int> pre(n, 0);
7        vector<int> suff(n, 0);
8        pre[0] = nums[0];
9        suff[n - 1] = nums[n - 1];
10
11        for(int i = 1; i < n; i++) {
12            pre[i] = max(nums[i], pre[i - 1]);
13        }
14        for(int i = n - 2; i >= 0; i--) {
15            suff[i] = min(nums[i], suff[i + 1]);
16        }
17        for(int i = 0; i < n; i++) {
18            int x = pre[i] - suff[i];
19            if(x <= k) {
20                ans = i;
21                break;
22            }
23        }
24        return ans;
25    }
26};