// Last updated: 11/1/2026, 10:21:22 AM
1class Solution {
2    public int[] twoSum(int[] nums, int target) {
3        HashMap<Integer, Integer> mp = new HashMap<>();
4
5        for(int i = 0; i < nums.length; i++) {
6            int x = target - nums[i];
7            if(mp.containsKey(x)) {
8                return new int[]{i, mp.get(x)};
9            }
10            mp.put(nums[i], i);
11        }
12        return new int[]{-1, -1};
13    }
14}