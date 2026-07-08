// Last updated: 7/8/2026, 10:35:20 AM
1class Solution {
2public:
3    int deleteAndEarn(vector<int>& nums) {
4        int maxi = *max_element(nums.begin(), nums.end());
5
6        vector<int> points(maxi + 1, 0);
7
8        for(int x : nums) {
9            points[x] += x;
10        }
11
12        int a = 0;
13        int b = points[0];
14
15        for(int i = 1; i <= maxi; i++) {
16            int c = max(b, a + points[i]);
17            a = b;
18            b = c;
19        }
20        return b;
21    }
22};