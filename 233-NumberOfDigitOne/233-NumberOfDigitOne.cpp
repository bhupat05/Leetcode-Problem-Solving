// Last updated: 3/18/2026, 2:28:40 PM
class Solution {
public:
    // dp[position][tight][countOf1]
    int dp[20][2][20];

    int dfs(string &num, int pos, int tight, int count1) {
        // If all digits are processed
        if (pos == num.size()) {
            return count1;
        }

        // Memoization check
        if (dp[pos][tight][count1] != -1) {
            return dp[pos][tight][count1];
        }

        int limit = tight ? num[pos] - '0' : 9;
        int result = 0;

        // Try all digits at current position
        for (int digit = 0; digit <= limit; digit++) {
            int newCount1 = count1 + (digit == 1);
            int newTight = tight && (digit == limit);

            result += dfs(num, pos + 1, newTight, newCount1);
        }

        return dp[pos][tight][count1] = result;
    }

    int countDigitOne(int n) {
        string num = to_string(n);
        memset(dp, -1, sizeof(dp));
        return dfs(num, 0, 1, 0);
    }
};
