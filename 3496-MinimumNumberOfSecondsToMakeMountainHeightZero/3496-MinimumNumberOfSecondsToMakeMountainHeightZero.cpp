// Last updated: 3/18/2026, 2:21:16 PM
class Solution {
public:
    int help(long long x, long long t) {
        long long temp = (8 * t) / x;
        int n = (sqrt(1 + temp) - 1) / 2;
        return n;
    }

    long long minNumberOfSeconds(int x, vector<int>& nums) {
        //sort(nums.begin(), nums.end());

        long long l = 1, r = 1e18;
        long long ans = r;

        while(l <= r) {
            long long mid = (l + r) / 2;

            long long remaining = x;

            for(int i = 0; i < nums.size(); i++) {
                int n = help(nums[i], mid);
                remaining -= n;
                if(remaining <= 0) break;
            }

            if(remaining <= 0) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};