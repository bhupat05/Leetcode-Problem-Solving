// Last updated: 4/20/2026, 8:52:54 AM
1class Solution {
2public:
3    int maxDistance(vector<int>& colors) {
4        int n = colors.size();
5        int ans = 0;
6
7        for(int i = 0; i < n; i++) {
8            for(int j = i; j < n; j++) {
9                if(colors[i] != colors[j])
10                ans = max(ans, j - i);
11            }
12        }
13        return ans;
14    }
15};