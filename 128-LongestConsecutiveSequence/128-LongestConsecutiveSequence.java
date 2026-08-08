// Last updated: 8/8/2026, 11:26:36 AM
1import java.util.*;
2
3class Solution {
4    public int longestConsecutive(int[] nums) {
5        int n = nums.length;
6
7        if (n == 0) return 0;
8
9        Arrays.sort(nums);
10
11        int ans = 1;
12        int curr = 1;
13
14        for (int i = 1; i < n; i++) {
15
16            if (nums[i] == nums[i - 1]) {
17                continue;
18            }
19
20            if (nums[i] == nums[i - 1] + 1) {
21                curr++;
22            } else {
23                ans = Math.max(ans, curr);
24                curr = 1;
25            }
26        }
27
28        return Math.max(ans, curr);
29    }
30}