// Last updated: 3/18/2026, 3:02:26 PM
class Solution {
public:
    double myPow(double x, int n) {
        long long power = n;
        double result = 1.0;


        if(power < 0) {
            x = 1.0 / x;
            power = -power;
        }

        while(power > 0) {
            if(power & 1) {
                result *= x;
            }
            x *= x;

            power >>= 1;
        }

        return result;

    }
};