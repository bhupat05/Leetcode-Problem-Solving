// Last updated: 9/14/2026, 9:55:16 PM
1class Solution {
2public:
3    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
4        int m = firstList.size();
5        int n = secondList.size();
6        int l = 0; 
7        int r = 0;
8        vector<vector<int>> ans;
9
10        while(l < m && r < n) {
11            int x1 = firstList[l][0];
12            int y1 = firstList[l][1];
13            int x2 = secondList[r][0];
14            int y2 = secondList[r][1];
15
16            int x = max(x1, x2);
17            int y = min(y1, y2);
18            if(x <= y) {
19                ans.push_back({x, y});
20            }
21            if(y1 < y2) {
22                l++;
23            } else {
24                r++;
25            }
26        }
27        return ans;
28    }
29};