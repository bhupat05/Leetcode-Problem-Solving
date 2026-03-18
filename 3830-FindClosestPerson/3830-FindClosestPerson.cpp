// Last updated: 3/18/2026, 2:20:34 PM
class Solution {
public:
    int findClosest(int x, int y, int z) {
        if(abs(x-z) < abs(y-z)) return 1;
        else if(abs(x-z) > abs(y-z)) return 2;
        else return 0;
    }
};