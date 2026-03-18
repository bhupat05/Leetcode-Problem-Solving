// Last updated: 3/18/2026, 2:29:00 PM
class Solution {
public:
    int roblinear(vector<int>& nums, int start, int end) {
        int a = 0;
        int b = 0;
        for(int i = start; i <= end; i++) {
            int c = max(a + nums[i], b);
            a = b;
            b = c;
        }
        return b;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        int r1 = roblinear(nums, 0, n - 2);
        int r2 = roblinear(nums, 1, n - 1);

        return max(r1, r2);
    }
};