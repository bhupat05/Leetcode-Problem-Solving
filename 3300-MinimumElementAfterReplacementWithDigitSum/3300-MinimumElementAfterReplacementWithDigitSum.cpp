// Last updated: 5/29/2026, 9:58:39 AM
1class Solution {
2public:
3    int minElement(vector<int>& nums) {
4        int n = nums.size();
5        int mini = nums[0];
6
7        for(int x : nums) {
8            int sum = 0;
9            while(x > 0) {
10                sum += x % 10;
11                x /= 10;
12            }
13            mini = min(mini, sum);
14        }
15        return mini;
16    }
17};