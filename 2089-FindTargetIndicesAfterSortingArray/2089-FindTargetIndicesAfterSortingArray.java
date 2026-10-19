// Last updated: 10/19/2026, 10:53:41 PM
1class Solution {
2    public List<Integer> targetIndices(int[] nums, int target) {
3        Arrays.sort(nums);
4        List<Integer> ans = new ArrayList<>();
5
6        for(int i = 0; i < nums.length; i++) {
7            if(nums[i] == target) {
8                ans.add(i);
9            }
10        }
11        return ans;
12    }
13}