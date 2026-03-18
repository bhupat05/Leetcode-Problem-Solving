// Last updated: 3/18/2026, 2:28:04 PM
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        int i = 0;                     
        int j = -1;                   

        for (int k = 1; k < n; k++) {
            if (nums[k] <= nums[i]) {
                i = k;

            } else if (j == -1 || nums[k] <= nums[j]) {
                j = k;

            } else {
                return true;
                
            }
        }

        return false;
    }
};
