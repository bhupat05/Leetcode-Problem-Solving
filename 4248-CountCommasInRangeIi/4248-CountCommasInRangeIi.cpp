// Last updated: 3/18/2026, 2:19:05 PM
class Solution {
public:
    long long countCommas(long long n) {
        long long r = 0;

        if(n >= 1000){
            long long a = min(n, 999999LL);
            r += (a - 1000 + 1) * 1;
        }

        if(n >= 1000000){
            long long a = min(n, 999999999LL);
            r += (a - 1000000 + 1) * 2;
        }

        if(n >= 1000000000){
            long long a = min(n, 999999999999LL);
            r += (a - 1000000000 + 1) * 3;
        }

        if(n >= 1000000000000LL){
            long long a = min(n, 999999999999999LL);
            r += (a - 1000000000000LL + 1) * 4;
        }

        if(n >= 1000000000000000LL){
            r += (n - 1000000000000000LL + 1) * 5;
        }

        return r;
    }
};