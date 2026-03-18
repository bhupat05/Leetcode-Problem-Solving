// Last updated: 3/18/2026, 2:19:34 PM
class Solution {
public:
    int minimumFlips(int n) {
        int r = 0;
        int x = n;

        while(x > 0) {
            r <<= 1;
            r |= (x & 1);
            x >>= 1;
        }

         x = n ^ r;
        int count = 0;

        while(x > 0) {
            count += (x & 1);
            x >>= 1;
        }

        return count;
        
    }
};