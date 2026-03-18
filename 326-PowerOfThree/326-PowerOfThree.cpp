// Last updated: 3/18/2026, 2:28:09 PM
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;

        while(n % 3 == 0){
            n /= 3;
        }

        return n == 1;

    }
};