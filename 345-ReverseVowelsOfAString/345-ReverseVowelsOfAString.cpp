// Last updated: 3/18/2026, 2:27:57 PM
class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    string reverseVowels(string s) {
        int l = 0, r = s.length() - 1;

        while (l < r) {
            while (l < r && !isVowel(s[l])) l++;  // <-- check l < r
            while (l < r && !isVowel(s[r])) r--;  // <-- check l < r

            if (l < r) {
                swap(s[l], s[r]);
                l++;
                r--;
            }
        }
        return s;
    }
};
