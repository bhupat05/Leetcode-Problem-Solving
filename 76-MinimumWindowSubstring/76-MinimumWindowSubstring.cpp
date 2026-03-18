// Last updated: 3/18/2026, 3:01:51 PM
class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        if (n > m) return "";

        vector<int> v(128, 0);

        for (char c : t) v[c]++;

        int req = n;
        int l = 0;
        int minLen = INT_MAX;
        int start = 0;

        for (int i = 0; i < m; i++) {
            v[s[i]]--;
            if (v[s[i]] >= 0) req--;

            while (req == 0) {
                if (i - l + 1 < minLen) {
                    minLen = i - l + 1;
                    start = l;
                }

                v[s[l]]++;
                if (v[s[l]] > 0) req++;
                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
