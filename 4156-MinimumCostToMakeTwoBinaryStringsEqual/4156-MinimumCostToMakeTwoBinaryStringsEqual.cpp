// Last updated: 3/18/2026, 2:19:20 PM
class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        int n = s.size();
        long long a = 0, b = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                if (s[i] == '0') {
                     a++;
                }
                else {
                    b++;
                }
            }
        }

        string qui = s + "|" + t;

        long long result = 0;

        long long m = min(a, b);
        result += m * min((long long)swapCost, 2LL * flipCost);
        a -= m;
        b -= m;

        long long r = a + b;
        if (r > 0) {
            long long pairCost = min(2LL * flipCost,
                                     (long long)crossCost + (long long)swapCost);
            result += (r / 2) * pairCost;
            if (r % 2) result += flipCost;
        }

        return result;
    }
};
