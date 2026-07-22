// Last updated: 7/22/2026, 3:52:25 PM
1class Solution {
2public:
3    int longestConsecutive(vector<int>& nums) {
4        unordered_set<int> st(nums.begin(), nums.end());
5        int longest = 0;
6
7        for (int x : st) {
8            if (!st.count(x - 1)) {
9                int y = x;
10                while (st.count(y)) y++;
11                longest = max(longest, y - x);
12            }
13        }
14
15        return longest;
16    }
17};