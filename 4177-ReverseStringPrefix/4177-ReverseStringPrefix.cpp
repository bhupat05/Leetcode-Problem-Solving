// Last updated: 3/18/2026, 2:19:10 PM
class Solution {
public:
    string reversePrefix(string s, int k) {

       reverse(s.begin(), s.begin() + k);
        return s;
        
        
    }
};