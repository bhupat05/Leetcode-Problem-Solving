// Last updated: 3/18/2026, 2:27:53 PM
class Solution {
public:
    int getSum(int a, int b) {
        while(b){
            int carry = (a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};