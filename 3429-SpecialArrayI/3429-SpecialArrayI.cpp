// Last updated: 3/18/2026, 2:21:27 PM
class Solution {
public:
    int parity(int x) {
        return x % 2;
    }

    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;

        for (int i = 1; i < n; i++) {
            if (parity(nums[i]) == parity(nums[i - 1])) {
                return false;
            }
        }
        return true;
    }
};
