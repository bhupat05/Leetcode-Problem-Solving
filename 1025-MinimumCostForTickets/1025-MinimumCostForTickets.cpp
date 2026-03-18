// Last updated: 3/18/2026, 2:25:40 PM
class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs, int idx, vector<int>& dp) {
        int n = days.size();

        if (idx >= n) return 0;

        if(dp[idx] != -1) return dp[idx];

        int i = idx;
        while (i < n && days[i] < days[idx] + 1) i++;
        int cost1 = costs[0] + solve(days, costs, i, dp);


        i = idx;
        while (i < n && days[i] < days[idx] + 7) i++;
        int cost7 = costs[1] + solve(days, costs, i, dp);

        i = idx;
        while (i < n && days[i] < days[idx] + 30) i++;
        int cost30 = costs[2] + solve(days, costs, i, dp);

        return dp[idx] = min({cost1, cost7, cost30});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, -1);
        return solve(days, costs, 0, dp);
    }
};
