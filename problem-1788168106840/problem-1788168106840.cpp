// Last updated: 8/31/2026, 2:51:46 PM
1class Solution {
2public:
3    int minBishopMoves(vector<int>& source, vector<int>& target) {
4        if((source[0] + source[1]) % 2 != (target[0] + target[1]) % 2) return -1;
5
6        if(abs(source[0] - target[0]) == abs(source[1] - target[1])) return 1;
7        return 2;
8    }
9};