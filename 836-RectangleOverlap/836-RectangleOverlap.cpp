// Last updated: 9/14/2026, 4:28:18 PM
1class Solution {
2public:
3    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
4        if(rec2[3] <= rec1[1] || rec2[1] >= rec1[3]) return false;
5        if(rec2[2] <= rec1[0] || rec2[0] >= rec1[2]) return false;
6
7
8        return true;
9    }
10};