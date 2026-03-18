// Last updated: 3/18/2026, 2:25:18 PM
class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        int m = a.size();
        int n = b.size();

        if (n > m) swap(a, b), swap(m, n);  // ensure 'b' is smaller to save memory

        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i - 1] == b[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }

        return prev[n];
    }
};
