// Last updated: 3/18/2026, 2:19:43 PM
class Solution {
public:
    int maxDistinct(string s) {
        vector<int> v(26, 0);

        for(char c : s) {
            v[c - 'a']++;
        }
        int count = 0;

        for(int x : v) {
            if(x != 0) {
                count++;
            }
        }

        return count;

        
    }
};