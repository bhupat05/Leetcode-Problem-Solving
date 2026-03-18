// Last updated: 3/18/2026, 2:23:25 PM
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0 || n == 1) return 0;
        sort(nums.begin(), nums.end());

        int mini = INT_MAX;

        mini = min(mini, nums[k - 1] - nums[0]);
        int l = 0;

        for(int i = k - 1; i < n; i++) {
            mini = min(mini, nums[i] - nums[l]);
            l++;
        }

        return mini;

    }
};