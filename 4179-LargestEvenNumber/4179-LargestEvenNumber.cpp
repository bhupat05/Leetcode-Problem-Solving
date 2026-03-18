// Last updated: 3/18/2026, 2:19:09 PM
class Solution {
public:
    string largestEven(string s) {
        int n = s.size();

        int l = -1;

        for(int i = 0; i < n; i++) {
            if(s[i] == '2') {
                l = i;
            }
        }

        if(l == -1) return "";

        return s.substr(0, l + 1);
    }
};