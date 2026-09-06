// Last updated: 9/6/2026, 11:50:09 AM
1class Solution {
2public:
3    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
4        int n = position.size();
5        if(n== 1) return 1;
6        int cnt = 1;
7        
8        for(int i = n - 2; i >= 0; i--) {
9            if(position[i + 1] - position[i] <= distance) {
10                speed[i] = speed[i + 1];
11            } else if(speed[i] <= speed[i + 1]) {
12                cnt++;
13            } else if(speed[i] > speed[i + 1]) {
14                speed[i] = speed[i + 1];
15            }
16        }
17        return cnt;
18    }
19};