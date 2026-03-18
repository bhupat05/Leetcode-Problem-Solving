// Last updated: 3/18/2026, 2:22:44 PM
class Solution {
public:
    char repeatedCharacter(string s) {
        int n = s.length();
        vector<int> v(26, 0);

        for(int i = 0; i < n; i++) {
            if(v[s[i] - 'a'] != 0) {
                return s[i];
            }
            v[s[i] - 'a']++;
        } 
        return ' ';
    }
};