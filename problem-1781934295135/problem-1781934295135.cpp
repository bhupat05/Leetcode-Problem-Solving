// Last updated: 6/20/2026, 11:14:55 AM
1class Solution {
2public:
3    bool increasingTriplet(vector<int>& nums) {
4        int n = nums.size();
5
6        vector<bool> l(n, false);
7        vector<bool> r(n, false);
8        int mini = nums[0];
9
10        for(int i = 1; i < n; i++) {
11            if(nums[i] > mini) {
12                l[i] = true;
13            }
14            mini = min(mini, nums[i]);
15        }
16        mini = nums[n - 1];
17
18        for(int i = n - 2; i >= 0; i--) {
19            if(nums[i] < mini) {
20                r[i] = true;
21            }
22            mini = max(mini, nums[i]);
23        }
24
25        for(int i = 0; i < n; i++) {
26            if(l[i] && r[i]) return true;
27        }
28        return false;
29    }
30};