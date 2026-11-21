// Last updated: 11/21/2026, 2:51:11 PM
1import java.util.*;
2
3class Solution {
4    public int[] maxSlidingWindow(int[] nums, int k) {
5        int n = nums.length;
6        Deque<Integer> dp = new ArrayDeque<>();
7        ArrayList<Integer> arr = new ArrayList<>();
8
9        for (int i = 0; i < n; i++) {
10
11            if(!dp.isEmpty() && dp.getLast() <= i - k)
12                dp.removeLast();
13
14            while(!dp.isEmpty() && nums[dp.getFirst()] <= nums[i])
15                dp.removeFirst();
16
17            dp.addFirst(i);
18
19            if (i >= k - 1) {
20                arr.add(nums[dp.getLast()]);
21            }
22        }
23
24        int[] ans = new int[arr.size()];
25
26        for (int i = 0; i < arr.size(); i++) {
27            ans[i] = arr.get(i);
28        }
29
30        return ans;
31    }
32}