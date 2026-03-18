// Last updated: 3/18/2026, 2:29:47 PM
class Solution {
public:
    string reverseWords(string s) {
        string ans, word;

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ' ') continue;

            int j = i;
            while (j >= 0 && s[j] != ' ') j--;

            if (!ans.empty()) ans += " ";
            ans += s.substr(j + 1, i - j);

            i = j;
        }

        return ans;
    }
};
