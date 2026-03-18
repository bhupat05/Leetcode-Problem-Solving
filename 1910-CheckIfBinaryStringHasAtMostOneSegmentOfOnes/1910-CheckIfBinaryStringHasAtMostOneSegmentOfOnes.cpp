// Last updated: 3/18/2026, 2:23:44 PM
class Solution {
public:
    bool checkOnesSegment(string s) {
        int i = 0;
        int n = s.size();

        while(i < n && s[i] == '0') {
            i++;
        }

        while(i < n && s[i] == '1') i++;
        while(i < n && s[i] == '0') i++;

        return i == n;
        
    }
};