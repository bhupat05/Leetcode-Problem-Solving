// Last updated: 3/18/2026, 2:28:30 PM
class Solution {
public:
    int addDigits(int num) {
        //if(num == 0) return 0;
        return 1 + (num - 1) % 9;
    }
};