// Last updated: 6/12/2026, 9:48:35 AM
1class Solution {
2public:
3    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
4        unordered_set<int> st1(nums1.begin(), nums1.end());
5        unordered_set<int> st2(nums2.begin(), nums2.end());
6        vector<vector<int>>v(2);
7
8        for(auto x : st1) {
9            if(!st2.count(x)) {
10                v[0].push_back(x);
11            }
12        }
13
14        
15        for(auto x : st2) {
16            if(!st1.count(x)) {
17                v[1].push_back(x);
18            }
19        }
20        return v;
21
22    }
23};