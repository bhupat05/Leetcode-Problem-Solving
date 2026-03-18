// Last updated: 3/18/2026, 2:20:00 PM
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int l = 0;
        int cnt = n - 1;   

        for (int r = 0; r < n; r++) {
            long long m = (long long)nums[l] * k;

            while (m < nums[r]) {
                l++;
                m = (long long)nums[l] * k;
            }

            int windowSize = r - l + 1;
            cnt = min(cnt, n - windowSize);
        }

        return cnt;
    }
};
