// Last updated: 9/4/2026, 9:33:38 AM
1class Solution {
2public:
3    int sumOfGoodIntegers(int n, int k) {
4        int sum = 0;
5        for(int i = 1; i <= k + n; i++) {
6            if((abs(n - i) <= k) &&((n & i) == 0)) {
7                sum += i;
8            }
9        }
10        return sum;
11    }
12};