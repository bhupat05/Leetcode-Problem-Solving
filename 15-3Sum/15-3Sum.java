// Last updated: 8/8/2026, 3:46:45 PM
1class Solution {
2    public List<List<Integer>> threeSum(int[] nums) {
3        int n = nums.length;
4        Arrays.sort(nums);
5        List<List<Integer>> ans =new ArrayList<>();
6
7        for(int i = 0; i < n; i++) {
8            int l = i + 1;
9            int r = n - 1;
10            if(i > 0 && nums[i] == nums[i - 1]) continue;
11
12            while(l < r) {
13
14               
15                int sum = nums[l] + nums[r] + nums[i];
16
17                if(sum == 0) {
18                    List<Integer> temp = new ArrayList<>();
19                    temp.add(nums[l]);
20                    temp.add(nums[r]);
21                    temp.add(nums[i]);
22                    ans.add(temp);
23                    l++;
24                    r--;
25                    while(l < r && nums[l] == nums[l - 1]) l++;
26                    while(l < r && nums[r] == nums[r + 1]) r--;
27                } else if(sum < 0) {
28                    l++;
29                } else {
30                    r--;
31                }
32            }
33        }
34        return ans;
35    }
36}