// Last updated: 3/18/2026, 2:27:45 PM
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;

        for (char c : t) {
            if (j < s.size() && c == s[j]) {
                j++;
            }
        }

        return j == s.size();
    }
};
