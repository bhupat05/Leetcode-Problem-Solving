// Last updated: 3/18/2026, 3:02:32 PM
class Solution {
public:
    vector<vector<int>> t;

    bool solve(int i, int j, const string &s, const string &p) {
        // If we've reached the end of the pattern, check if we've also reached the end of the string
        if (j == p.length()) {
            return (i == s.length());
        }
        if (t[i][j] != -1) {
            return t[i][j];
        }

        // Match if current characters are the same or pattern has '?'
        bool fcm = (i < s.length() && (p[j] == s[i] || p[j] == '?'));

        // If pattern has '*' at current position
        if (p[j] == '*') {
            // Either match '*' as empty (skip '*' in pattern) or match it with current character in `s`
            bool skipStar = solve(i, j + 1, s, p);         // '*' matches empty sequence
            bool matchStar = (i < s.length() && solve(i + 1, j, s, p)); // '*' matches one or more characters in `s`
            return t[i][j] = skipStar || matchStar;
        }

        // Proceed with the next character if the current characters match
        return t[i][j] = fcm && solve(i + 1, j + 1, s, p);
    }

    bool isMatch(string s, string p) {
        t.resize(s.length() + 1, vector<int>(p.length() + 1, -1));
        return solve(0, 0, s, p);
    }
};
