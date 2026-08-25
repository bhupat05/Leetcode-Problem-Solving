// Last updated: 8/26/2026, 12:05:33 AM
1class Solution {
2public:
3    int missingMultiple(vector<int>& nums, int k) {
4        int n = nums.size();
5        unordered_set<int> st(nums.begin(), nums.end());
6        int i = 1;
7        while(i) {
8            if((!st.count(i)) && (i % k == 0)) return i;
9            i++;
10        }
11        return -1;
12    }
13};