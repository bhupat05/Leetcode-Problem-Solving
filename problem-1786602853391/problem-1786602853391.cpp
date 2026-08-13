// Last updated: 8/13/2026, 12:04:13 PM
1class Solution {
2public:
3    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
4        int n = nums.size();
5        int c1 = 0;
6        int c2 = 0;
7        int ans = 0;
8        int mod = 1e9 + 7;
9
10        for(int i = 0; i < n; i++) {
11            if(nums[i] < a) {
12                ans = (ans + c1 + c2) % mod;
13            } else if(nums[i] >= a && nums[i] <= b) {
14                ans = (ans + c2) % mod;
15                c1++;
16            } else {
17                c2++;
18            }
19        }
20        return ans % mod;
21    }
22};