// Last updated: 9/15/2026, 11:31:42 PM
1class Solution {
2public:
3    int jump(vector<int>& nums) {
4        int n = nums.size();
5
6        int mx = 0;
7        int cnt = 0;
8        int idx = 0;
9        for(int i = 0; i < n; i++) {
10            mx = max(mx, i + nums[i]);
11            if(idx >= n - 1) return cnt;
12            if(i == idx) {
13                cnt++;
14                idx = mx;
15            }
16            
17            
18        }
19        return cnt;
20    }
21};