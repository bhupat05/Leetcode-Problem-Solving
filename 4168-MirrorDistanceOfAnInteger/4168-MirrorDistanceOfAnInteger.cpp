// Last updated: 3/18/2026, 2:19:14 PM
class Solution {
public:
    int mirrorDistance(int n) {

        int x = n;

        int y = 0;

        while(x > 0) {
            y = y * 10 + x % 10;
            x /= 10;
        }

        return abs(n - y);
    }
};