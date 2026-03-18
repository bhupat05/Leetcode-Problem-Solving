// Last updated: 3/18/2026, 2:19:12 PM
class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> suff(n + 1, INT_MAX);

       

        for(int i = n - 1; i >= 0; i--) {
            suff[i] = min(suff[i + 1], nums[i]);
        }

        long long pre = 0;
        long long ans = LLONG_MIN;

        for(int i = 0; i < n - 1; i++) {
            pre += nums[i];
            long long x = pre - suff[i + 1];
            ans = max(ans, x);
        }
        return ans;
    }
};