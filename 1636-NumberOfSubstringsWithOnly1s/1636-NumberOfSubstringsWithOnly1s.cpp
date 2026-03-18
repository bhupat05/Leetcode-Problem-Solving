// Last updated: 3/18/2026, 2:24:13 PM
class Solution {
public:
    int numSub(string s) {
        int n = s.length();
        long long result = 0;
        long long l = 0;
         const long long MOD = 1e9 + 7;

        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                l++;
            } else {
                result += l * (l + 1) / 2;
                l = 0;
            }
        }
        result = (result + l * (l + 1) / 2) % MOD;
        return result;
    }
};
