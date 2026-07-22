// Last updated: 7/22/2026, 3:55:07 PM
1class Solution {
2public:
3    int longestConsecutive(vector<int>& nums) {
4        unordered_set<int> st(nums.begin(), nums.end());
5
6        int ans = 0;
7
8        for (int x : st) {
9            if (!st.count(x - 1)) {   
10                int len = 1;
11                while (st.count(x + 1)) {
12                    x++;
13                    len++;
14                }
15                ans = max(ans, len);
16            }
17        }
18
19        return ans;
20    }
21};