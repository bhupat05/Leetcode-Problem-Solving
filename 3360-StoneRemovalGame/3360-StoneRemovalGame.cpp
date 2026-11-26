// Last updated: 11/26/2026, 7:18:30 PM
1class Solution {
2public:
3    bool canAliceWin(int n) {
4        int remove = 10;
5        bool aliceTurn = true;
6
7        while (n >= remove) {
8            n -= remove;
9            remove--;
10
11            aliceTurn = !aliceTurn;
12        }
13
14        return !aliceTurn;
15    }
16};