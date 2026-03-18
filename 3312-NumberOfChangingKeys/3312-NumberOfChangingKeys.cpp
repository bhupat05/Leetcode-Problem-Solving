// Last updated: 3/18/2026, 2:21:40 PM
class Solution {
public:
    int countKeyChanges(string s) {
        int n = s.size();
        int change = 0;
        char last = tolower(s[0]);

        for (int i = 1; i < n; i++) {
            char curr = tolower(s[i]);
            if (curr != last) {
                change++;
                last = curr;
            }
        }
        return change;
    }
};
