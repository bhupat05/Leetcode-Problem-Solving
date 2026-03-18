// Last updated: 3/18/2026, 2:25:55 PM
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        int m = INT_MIN;
        int count = 0;

        for (int j = 0; j < n; j++) {
            m = max(m, nums[j]);
            if (nums[j] < 0) count++;
        }

        if (count == n) return m;

        int maxi = INT_MIN;
        int curr = 0;

        for (int i = 0; i < n; i++) {
            curr += nums[i];          
            if (curr < 0) curr = 0;
            maxi = max(maxi, curr);
        }

        int mini = INT_MAX;
        curr = 0;
        int total = 0;

        for (int i = 0; i < n; i++) {
            curr += nums[i];
            mini = min(mini, curr);
            if (curr > 0) curr = 0;
            total += nums[i];
        }

        return max(maxi, total - mini);
    }
};
