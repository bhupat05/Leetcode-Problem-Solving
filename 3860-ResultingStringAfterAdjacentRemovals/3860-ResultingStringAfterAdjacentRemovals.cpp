// Last updated: 3/18/2026, 2:20:23 PM
class Solution {
public:
    string resultingString(string s) {
        int j = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (j > 0 && help(s[j-1], s[i])) {
                j--;
            } else {
                s[j++] = s[i];
            }
        }

        return s.substr(0, j);
    }

private:
    bool help(char a, char b) {
        if (abs(a - b) == 1) return true;
        if ((a == 'a' && b == 'z') || (a == 'z' && b == 'a')) return true;
        return false;
    }
};
