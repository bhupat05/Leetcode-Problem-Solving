// Last updated: 4/13/2026, 12:24:36 AM
1class Solution {
2public:
3    bool search(vector<int>& nums, int target) {
4        int l = 0, r = nums.size() - 1;
5
6        while (l <= r) {
7            int mid = l + (r - l) / 2;
8
9            if (nums[mid] == target) return true;
10
11            if (nums[l] == nums[mid] && nums[mid] == nums[r]) {
12                l++;
13                r--;
14            }
15            else if (nums[l] <= nums[mid]) {
16                if (target >= nums[l] && target < nums[mid])
17                    r = mid - 1;
18                else
19                    l = mid + 1;
20            }
21            else {
22                if (target > nums[mid] && target <= nums[r])
23                    l = mid + 1;
24                else
25                    r = mid - 1;
26            }
27        }
28        return false;
29    }
30};