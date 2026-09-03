// Last updated: 9/3/2026, 10:55:23 AM
1class Solution {
2public:
3    bool uniformArray(vector<int>& nums1) {
4        int mn = nums1[0];
5        bool isOdd = false;
6
7        for(int x : nums1) {
8            mn = min(mn, x);
9            if(x & 1) {
10                isOdd = true;
11            }
12        }
13        return (mn & 1) == isOdd;
14    }
15};