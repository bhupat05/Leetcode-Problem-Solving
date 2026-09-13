// Last updated: 9/13/2026, 2:49:58 PM
1class Solution {
2public:
3    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
4        vector<pair<int, int>> v1;
5        vector<pair<int, int>> v2;
6        int n = img1.size();
7
8        for(int i = 0; i < n; i++) {
9            for(int j = 0; j < n; j++) {
10                if(img1[i][j]) {
11                    v1.push_back({i,j});
12                }
13
14                if(img2[i][j]) {
15                    v2.push_back({i,j});
16                }
17            }
18        }
19
20        map<pair<int, int>, int> mp;
21        int ans = 0;
22        for(auto[x, y] : v1) {
23            for(auto[X, Y] : v2) {
24                mp[{x - X, y - Y}]++;
25                ans = max(ans, mp[{x - X, y - Y}]);
26            } 
27        }
28        return ans;
29    }
30};