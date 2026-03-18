// Last updated: 3/18/2026, 2:22:26 PM
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> suff(n + 1, 0);

        // suffix Y count
        for (int i = n - 1; i >= 0; i--) {
            suff[i] = suff[i + 1] + (customers[i] == 'Y');
        }

        int prefixN = 0;
        int minPenalty = INT_MAX;
        int ans = 0;

        for (int i = 0; i <= n; i++) {
            int penalty = prefixN + suff[i];
            if (penalty < minPenalty) {
                minPenalty = penalty;
                ans = i;
            }
            if (i < n && customers[i] == 'N') {
                prefixN++;
            }
        }

        return ans;
    }
};
