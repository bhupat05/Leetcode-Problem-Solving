// Last updated: 3/18/2026, 2:22:25 PM
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();

        // Count negatives: first index where nums[i] >= 0
        int l = 0, r = n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < 0)
                l = mid + 1;
            else
                r = mid;
        }
        int neg = l;

        l = 0, r = n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] <= 0)
                l = mid + 1;
            else
                r = mid;
        }
        int pos = n - l;

        return max(neg, pos);
    }
};
