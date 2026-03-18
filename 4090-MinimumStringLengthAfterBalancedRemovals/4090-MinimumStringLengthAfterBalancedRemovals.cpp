// Last updated: 3/18/2026, 2:19:40 PM
class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int n = s.length();

        int cnt = 0;

        for(char &c : s) {
            if(c == 'a') {
                cnt++;
            }
        }

        return abs(n - 2 *cnt);
        
        
    }
};