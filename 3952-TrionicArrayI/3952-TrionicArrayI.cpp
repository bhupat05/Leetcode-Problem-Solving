// Last updated: 3/18/2026, 2:20:02 PM
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();

        int p = 0;
        int q = n - 1;

        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1]) {
                p = i;
            } else {
                break;
            }
        }

        for(int i = p + 1; i < n; i++) {
            if(nums[i] < nums[i - 1]) {
                q = i;
            } else {
                break;
            }
        }
        for(int i = q + 1; i < n; i++) {
            if(nums[i] <= nums[i - 1]) return false;
        }
        if(p == 0 || q == n - 1) return false;
        else return true;
    }
};