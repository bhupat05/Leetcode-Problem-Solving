// Last updated: 3/18/2026, 2:20:31 PM
class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        const int MOD = 1e9 + 7;

        vector<long long> dp(n + 1, 0), prefix(n + 1, 0);
        dp[0] = 1; 
        prefix[0] = 1;

        deque<int> maxD, minD;

        int l = 0;

        for (int r = 0; r < n; r++) {

            // maintain max deque
            while (!maxD.empty() && nums[maxD.back()] < nums[r])
                maxD.pop_back();
            maxD.push_back(r);

            // maintain min deque
            while (!minD.empty() && nums[minD.back()] > nums[r])
                minD.pop_back();
            minD.push_back(r);

            while (!maxD.empty() && !minD.empty() &&
                   nums[maxD.front()] - nums[minD.front()] > k) 
            {
                if (maxD.front() == l) maxD.pop_front();
                if (minD.front() == l) minD.pop_front();
                l++;
            }

            dp[r + 1] = prefix[r] - (l == 0 ? 0 : prefix[l - 1]);
            dp[r + 1] = (dp[r + 1] % MOD + MOD) % MOD;

            prefix[r + 1] = (prefix[r] + dp[r + 1]) % MOD;
        }

        return dp[n];
    }
};
