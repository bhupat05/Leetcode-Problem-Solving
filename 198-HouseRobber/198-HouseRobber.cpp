// Last updated: 3/18/2026, 2:29:19 PM
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int a = nums[0];                   // dp[i-2]
        int b = max(nums[0], nums[1]);     // dp[i-1]

        for (int i = 2; i < n; i++) {
            int c = max(a + nums[i], b);   // dp[i]
            a = b;
            b = c;
        }

        return b;  //  'b' always holds the best result up to the last house
    }
};
