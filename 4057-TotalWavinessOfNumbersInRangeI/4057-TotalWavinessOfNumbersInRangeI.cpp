// Last updated: 3/18/2026, 2:19:48 PM
class Solution {
public:
    int help(int x) {
        int r = 0;
        string s = to_string(x);

        if(s.size() < 3) return 0;

        for(int i = 1; i < s.size() - 1; i++) {
            int a = s[i - 1] - '0';
            int b = s[i] - '0';
            int c = s[i + 1] - '0';

            if((b > a && b > c) || (b < a && b < c)) {
                r++;
            }
        }
        return r;
    }
    int totalWaviness(int num1, int num2) {

        int count = 0;

        for(int i = num1; i <= num2; i++) {
            count += help(i);
        }
        return count;
    }
};