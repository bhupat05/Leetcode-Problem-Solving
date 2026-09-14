// Last updated: 9/14/2026, 9:49:34 PM
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
11            if((firstList[l][1] >= secondList[r][0] && firstList[l][1] <= secondList[r][1])
12                || (secondList[r][1] >= firstList[l][0] && secondList[r][1] <= firstList[l][1])) {
13                    ans.push_back({max(firstList[l][0], secondList[r][0]), min(firstList[l][1], secondList[r][1])});
14            }
15
16            if(firstList[l][1] >= secondList[r][1]) {
17                r++;
18            } else {
19                l++;
20            }
21        }
22        return ans;
23    }
24};