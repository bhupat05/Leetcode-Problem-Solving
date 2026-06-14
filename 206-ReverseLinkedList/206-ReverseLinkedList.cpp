// Last updated: 6/14/2026, 5:08:46 PM
1class Solution {
2public:
3    int rob(vector<int>& nums) {
4        int n = nums.size();
5        if(n == 1) return nums[0];
6        if(n == 2) return max(nums[0], nums[1]);
7
8        int a = nums[0];
9        int b = max(nums[0], nums[1]);
10
11        for(int i = 2; i < n; i++) {
12            int c = max(a + nums[i], b);
13            a = b;
14            b = c;
15        }
16        return b;
17    }
18};