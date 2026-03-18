// Last updated: 3/18/2026, 2:24:50 PM
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int result = 0;

        while (a > 0 || b > 0 || c > 0) {
            int abit = a & 1;
            int bbit = b & 1;
            int cbit = c & 1;

            if ((abit | bbit) != cbit) {
                if (cbit == 1) {
                    result += 1;      
                } else {
                    result += abit + bbit; 
                }
            }

            a >>= 1;
            b >>= 1;
            c >>= 1;
        }

        return result;
    }
};
