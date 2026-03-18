// Last updated: 3/18/2026, 2:19:24 PM
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if (need1 == 0 && need2 == 0) return 0;

        long long ans = 0;
        long long c1 = 1LL * cost1 * need1 + 1LL * cost2 * need2;

        int mini = min(need1, need2);

        
        long long c2 = 1LL * costBoth * mini + 1LL * cost1 * (need1 - mini)
                     + 1LL * cost2 * (need2 - mini);

        long long c3 = 1LL * max(need1, need2) * costBoth;

        if (c1 <= c2 && c1 <= c3) {
            ans = c1;
        } else if (c2 <= c1 && c2 <= c3) {
            ans = c2;
        } else {
            ans = c3;
        }

        return ans;
    }
};
