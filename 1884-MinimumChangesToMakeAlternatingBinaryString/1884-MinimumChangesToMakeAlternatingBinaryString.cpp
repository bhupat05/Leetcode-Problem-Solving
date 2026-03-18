// Last updated: 3/18/2026, 2:23:48 PM
class Solution {
public:
    int minOperations(string s) {
        int op1 = 0, op2 = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] != (i % 2 ? '1' : '0')) op1++;
            if(s[i] != (i % 2 ? '0' : '1')) op2++;
        }

        return min(op1, op2);
    }
};