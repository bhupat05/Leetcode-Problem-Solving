// Last updated: 7/27/2026, 10:44:10 PM
1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int l = 0;
5        int r = nums.size() - 1;
6
7        while(l <= r) {
8            int mid = l + (r - l) / 2;
9            if(nums[mid] == target) return mid;
10
11            if(nums[mid] > nums[r]) {
12                if(target < nums[mid]) {
13                    if(target > nums[r]) {
14                        r = mid - 1;
15                    } else {
16                        l = mid + 1;
17                    }
18                } else {
19                    l = mid + 1;
20                }
21            } else {
22                if(target > nums[mid]) {
23                    if(target <= nums[r]) {
24                        l = mid + 1;
25                    } else {
26                        r = mid - 1;
27                    }
28                } else {
29                    r = mid - 1;
30                }
31            }
32        }
33        return -1;
34    }
35};