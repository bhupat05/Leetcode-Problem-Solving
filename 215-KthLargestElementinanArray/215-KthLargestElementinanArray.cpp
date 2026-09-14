// Last updated: 9/14/2026, 5:37:02 PM
1class Solution {
2public:
3    int quickSelect(vector<int>& nums, int l, int r, int k) {
4        int pivot = nums[r];
5        int i = l;
6
7        for (int j = l; j < r; j++) {
8            if (nums[j] < pivot) {
9                swap(nums[i++], nums[j]);
10            }
11        }
12
13        swap(nums[i], nums[r]);
14
15        if (i == k)
16            return nums[i];
17
18        if (i < k)
19            return quickSelect(nums, i + 1, r, k);
20
21        return quickSelect(nums, l, i - 1, k);
22    }
23
24    int findKthLargest(vector<int>& nums, int k) {
25        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
26    }
27};