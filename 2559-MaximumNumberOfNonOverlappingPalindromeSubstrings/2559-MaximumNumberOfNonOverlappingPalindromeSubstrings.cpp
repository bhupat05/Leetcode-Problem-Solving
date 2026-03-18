// Last updated: 3/18/2026, 2:22:28 PM
class Solution {
public:
    bool isPal(const string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();
        int cnt = 0;

        for (int i = 0; i < n; ) {
            if (i + k - 1 < n && isPal(s, i, i + k - 1)) {
                cnt++;
                i += k;
            }
            else if (i + k < n && isPal(s, i, i + k)) {
                cnt++;
                i += k + 1;
            }
            else {
                i++;
            }
        }
        return cnt;
    }
};