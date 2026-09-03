// Last updated: 9/3/2026, 11:03:36 AM
1class Solution {
2public:
3    bool checkGoodInteger(int n) {
4        int dSum = 0;
5        int sSum = 0;
6        while(n > 0) {
7            dSum += (n % 10);
8            sSum += (n % 10) * (n % 10);
9            n = n / 10;
10        }
11        return (sSum - dSum) >= 50;
12    }
13};