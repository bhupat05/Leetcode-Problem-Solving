// Last updated: 3/18/2026, 2:23:00 PM
class Solution {
public:
    int numberOfWays(string corridor) {
        int n = corridor.size();
        vector<int> s;

        for (int i = 0; i < n; i++) {
            if (corridor[i] == 'S') {
                s.push_back(i);
            }
        }

        if (s.size() == 0 || s.size() % 2 != 0) {
            return 0;
        }

        long long ans = 1;
        int prev = s[1];

        for (int i = 2; i < s.size(); i += 2) {
            int len = s[i] - prev;
            ans = (ans * len) % 1000000007;
            prev = s[i + 1];
        }

        return ans;
    }
};
