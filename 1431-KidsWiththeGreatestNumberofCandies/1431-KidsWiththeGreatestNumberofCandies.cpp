// Last updated: 6/10/2026, 8:26:41 AM
1class Solution {
2public:
3    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
4        int n = candies.size();
5        vector<bool> r(n, false);
6
7        int maxi = *max_element(candies.begin(), candies.end());
8
9        for(int i = 0; i < n; i++) {
10            if(candies[i] + extraCandies >= maxi) r[i] = true;
11        }
12        return r;
13    }
14};