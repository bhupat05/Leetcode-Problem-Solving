// Last updated: 3/18/2026, 2:23:32 PM
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> first(26, -1);
        vector<int> last(26, -1);

        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            if (first[idx] == -1) first[idx] = i;
            last[idx] = i;
        }

        int count = 0;

        for (int c = 0; c < 26; c++) {
            if (first[c] == -1 || first[c] == last[c]) continue;

            unordered_set<char> mid;
            for (int i = first[c] + 1; i < last[c]; i++) {
                mid.insert(s[i]);
            }

            count += mid.size();  
        }

        return count;
    }
};
