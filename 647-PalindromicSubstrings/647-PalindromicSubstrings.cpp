// Last updated: 3/18/2026, 2:26:54 PM
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;

        auto expand = [&](int left, int right) {
            int localCount = 0;
            while (left >= 0 && right < n && s[left] == s[right]) {
                localCount++;
                left--;
                right++;
            }
            return localCount;
        };

        for (int i = 0; i < n; i++) {
            count += expand(i, i);       // odd-length palindromes
            count += expand(i, i + 1);   // even-length palindromes
        }

        return count;
    }
};
