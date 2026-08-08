// Last updated: 8/8/2026, 10:08:35 PM
1class Solution {
2    static int bs(int[] nums, int target, int l, int r) {
3        while(l <=r) {
4            int mid = l + (r - l) / 2;
5
6            if(nums[mid] == target) return mid;
7            else if(nums[mid] < target) {
8                l = mid + 1;
9            } else {
10                r = mid - 1;
11            }
12        }
13        return -1;
14    }
15    public int search(int[] nums, int target) {
16        int l = 0;
17        int r = nums.length - 1;
18
19        while(l < r) {
20            int mid = l + (r - l) / 2;
21
22            if(nums[mid] > nums[r]) {
23                l = mid + 1;
24            } else {
25                r = mid;
26            }
27        }
28
29        int p = r;
30        l = 0;
31        r = nums.length - 1;
32        int ans = -1;
33        if(target >= nums[p] && target <= nums[r]) {
34            ans = bs(nums, target, p, r);
35        } else {
36            ans = bs(nums, target, 0, p);
37        }
38        return ans;
39    }
40}