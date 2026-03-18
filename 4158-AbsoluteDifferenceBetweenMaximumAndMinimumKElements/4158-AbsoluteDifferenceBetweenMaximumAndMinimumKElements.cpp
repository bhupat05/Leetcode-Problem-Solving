// Last updated: 3/18/2026, 2:19:17 PM
class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int small = 0, large = 0;

        for(int i = 0; i < k; i++) {
            small += nums[i];
        }

        for(int i = nums.size() - k; i < nums.size(); i++) {
            large += nums[i];
        }

        return abs(large - small);
    }
};
