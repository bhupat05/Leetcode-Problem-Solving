// Last updated: 3/18/2026, 2:19:52 PM
class Solution {
public:
    long long countDistinct(long long n) {
        string s = to_string(n);
        int len = s.size();

        long long pow9[20];
        pow9[0] = 1;
        for (int i = 1; i < 20; i++)
            pow9[i] = pow9[i - 1] * 9;

        long long ans = 0;

        for (int d = 1; d < len; d++)
            ans += pow9[d];

        for (int i = 0; i < len; i++) {
            int x = s[i] - '0';
            if (x == 0)
                return ans;
            for (int d = 1; d < x; d++)
                ans += pow9[len - i - 1];
        }

        return ans + 1;
    }
};
