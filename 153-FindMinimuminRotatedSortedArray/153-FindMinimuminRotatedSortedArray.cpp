// Last updated: 7/27/2026, 10:30:19 PM
1class Solution {
2public:
3    int findMin(vector<int>& nums) {
4        int n = nums.size();
5        int l = 0;
6        int r = n - 1;
7
8        while(l < r) {
9            int mid = l + (r - l) / 2;
10            if(nums[mid] < nums[r]) {
11                r = mid;
12            } else {
13                l = mid + 1;
14            }
15        }
16        return nums[l];
17    }
18};