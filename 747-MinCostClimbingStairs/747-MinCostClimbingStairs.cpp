// Last updated: 3/18/2026, 2:26:30 PM
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int a = 0; // dp[i-2]
        int b = 0; // dp[i-1]
        int c = 0; // dp[i]

        for (int i = 2; i <= n; i++) {
            c = min(b + cost[i - 1], a + cost[i - 2]);
            a = b;
            b = c;
        }

        return c;
    }
};
