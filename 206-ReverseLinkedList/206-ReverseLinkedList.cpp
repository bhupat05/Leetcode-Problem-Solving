// Last updated: 6/14/2026, 5:47:27 PM
1class Solution {
2public:
3    int minCostClimbingStairs(vector<int>& cost) {
4        int n = cost.size();
5        int a = 0;
6        int b = 0;
7
8        for(int i = 2; i <= n; i++) {
9            int c = min(a + cost[i - 2], b + cost[i - 1]);
10            a = b;
11            b = c;
12        }
13        return b;
14    }
15};