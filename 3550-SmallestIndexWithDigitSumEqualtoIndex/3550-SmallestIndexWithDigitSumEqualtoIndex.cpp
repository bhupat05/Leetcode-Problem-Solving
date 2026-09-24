// Last updated: 9/24/2026, 7:43:30 PM
1class Solution {
2public:
3    int smallestIndex(vector<int>& nums) {
4        for (int i = 0; i < min((int)nums.size(), 28); i++) {
5            int num = nums[i];
6            int sum = 0;
7
8            while (num > 0) {
9                sum += num % 10;
10                num /= 10;
11            }
12
13            if (sum == i)
14                return i;
15        }
16
17        return -1;
18    }
19};