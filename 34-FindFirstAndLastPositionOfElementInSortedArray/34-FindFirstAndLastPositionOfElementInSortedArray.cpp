// Last updated: 3/18/2026, 3:02:43 PM
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int p = -1;
        bool f = false;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) {
                p = mid;
                f = true;          
                break;
            } else if (target > nums[mid]) {
                l = mid + 1;      
            } else {
                r = mid - 1;     
            }
        }

        if (!f) return {-1, -1};

        int a = p, b = p;

        while (a - 1 >= 0 && nums[a - 1] == target) {
            a--;
        }

        while (b + 1 < n && nums[b + 1] == target) {
            b++;
        }

        return {a, b};
    }
};
