// Last updated: 3/18/2026, 2:19:06 PM
class Solution {
public:
    int countCommas(int n) {
        if(n < 1000) return 0;
        return n - 1000 + 1;
    }
};