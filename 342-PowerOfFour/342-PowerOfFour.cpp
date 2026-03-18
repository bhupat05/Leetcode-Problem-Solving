// Last updated: 3/18/2026, 2:28:02 PM
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;

        while(n % 4 == 0){
            n /= 4;
        }
        return n == 1;
    }
};