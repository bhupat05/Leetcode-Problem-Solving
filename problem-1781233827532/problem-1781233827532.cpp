// Last updated: 6/12/2026, 8:40:27 AM
1class Solution {
2public:
3    int pivotIndex(vector<int>& nums) {
4        int total = accumulate(nums.begin(), nums.end(), 0);
5        int leftSum = 0;
6
7        for (int i = 0; i < nums.size(); i++) {
8            int rightSum = total - leftSum - nums[i];
9
10            if (leftSum == rightSum)
11                return i;
12
13            leftSum += nums[i];
14        }
15
16        return -1;
17    }
18};