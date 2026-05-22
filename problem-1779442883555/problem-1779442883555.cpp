// Last updated: 5/22/2026, 3:11:23 PM
1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int l = 0;
5        int r = nums.size() - 1;
6
7        while(l <= r) {
8            int mid = l + (r - l) / 2;
9
10            if(nums[mid] == target) return mid;
11
12            if(nums[l] <= nums[mid]) {
13                if(target >= nums[l] && target < nums[mid]) {
14                    r = mid - 1;
15                } else {
16                    l = mid + 1;
17                }
18            } else {
19                if(target > nums[mid] && target <= nums[r]) {
20                    l = mid + 1;
21                } else {
22                    r = mid - 1;
23                }
24            }
25        }
26        return -1;
27    }
28};