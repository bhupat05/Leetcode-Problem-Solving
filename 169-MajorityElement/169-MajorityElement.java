// Last updated: 3/18/2026, 2:29:41 PM
class Solution {
    public int majorityElement(int[] nums) {
        
        Arrays.sort(nums);
        int n = nums.length;
        return nums[n/2];
    }
}