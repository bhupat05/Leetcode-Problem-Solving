// Last updated: 3/18/2026, 3:02:15 PM
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size() - 1;

        
        while (n >= 0 && s[n] == ' ') {
            n--;
        }

        
        int count = 0;
        while (n >= 0 && s[n] != ' ') {
            count++;
            n--;
        }

        return count;
    }
};
