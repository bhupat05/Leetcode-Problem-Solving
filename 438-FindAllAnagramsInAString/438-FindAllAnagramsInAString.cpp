// Last updated: 3/18/2026, 2:27:29 PM
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size();
        int n = p.size();

        vector<int> v(26, 0);
        vector<int> result;

        for (char c : p) {
            v[c - 'a']++;
        }

        int l = 0;
        vector<int> a(26, 0);

        for (int i = 0; i < m; i++) {
            a[s[i] - 'a']++;

            if (i - l + 1 > n) {
                a[s[l] - 'a']--;
                l++;
            }

            if (a == v) {
                result.push_back(l);
            }
        }
        return result;
    }
};
