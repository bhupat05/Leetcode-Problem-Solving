// Last updated: 8/12/2026, 10:37:41 AM
1class Solution {
2public:
3    bool canReach(vector<int>& start, vector<int>& target) {
4        return (start[0] + start[1] + target[0] + target[1]) %2 == 0;   
5    }
6};