// Last updated: 11/17/2026, 1:26:17 AM
1class Solution {
2    public List<List<Integer>> threeSum(int[] nums) {
3        int n = nums.length;
4        List<List<Integer>> ans = new ArrayList<>();
5        Arrays.sort(nums);
6
7        for(int i = 0; i < n; i++) {
8            if(i > 0 && nums[i] == nums[i - 1]) continue;
9
10            int l = i + 1;
11            int r = n - 1;
12
13            while(l < r) {
14                int sum = nums[i] + nums[l] + nums[r];
15                if(sum < 0) {
16                    l++;
17                } else if(sum > 0) {
18                    r--;
19                } else {
20                    ans.add(Arrays.asList(nums[i], nums[l], nums[r]));
21                    l++;
22                    r--;
23                    while(l < r && nums[l] == nums[l - 1]) l++;
24                    while(l < r && nums[r] == nums[r + 1]) r--;
25                }
26            }
27        }
28        return ans;
29    }
30}