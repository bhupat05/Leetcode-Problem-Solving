// Last updated: 8/6/2026, 10:52:02 PM
1class Solution {
2public:
3    int countRatioSubarrays(vector<int>& nums, int a, int b) {
4        int n = nums.size();
5        vector<int> e(n + 1, 0);
6        vector<int> o(n + 1, 0);
7        int cnt = 0;
8
9        for(int i = 0; i < n; i++) {
10            if(nums[i] % 2 == 0) {
11                e[i + 1] = e[i] + 1;
12                o[i + 1] = o[i];
13            } else {
14                e[i + 1] = e[i];
15                o[i + 1] = o[i] + 1;
16            }
17        }
18
19        for(int i = 0; i < n; i++) {
20            for(int j = i; j < n; j++) {
21                int x = (e[j + 1] - e[i]);
22                int y = (o[j + 1] - o[i]);
23                if(y > 0 && ((x * b) <= (a * y))) {
24                    cnt++;
25                    
26                }
27            }
28        }
29        return cnt;
30    }
31};