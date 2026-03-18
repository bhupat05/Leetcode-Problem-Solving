// Last updated: 3/18/2026, 3:03:23 PM
class Solution {
public:
    string solve(string &s, int l, int r) {
        int n = s.size();

        while(l >= 0 && r < n && s[l] == s[r]) {
            l--;
            r++;
        }
        return s.substr(l + 1, r - l - 1);
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string result = "";

        for(int i = 0; i < n; i++) {
            string odd = solve(s, i, i);
            if(odd.size() > result.size()) {
                result = odd;
            }

            string even = solve(s, i, i + 1);
            if(even.size() > result.size()) {
                result = even;
            }
        }
        return result;
    }
};