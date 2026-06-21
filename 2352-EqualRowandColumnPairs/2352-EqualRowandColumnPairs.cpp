// Last updated: 6/21/2026, 8:48:06 AM
1class Solution {
2public:
3    void pri(vector<int>& a) {
4        for(int i = 0; i < a.size(); i++) {
5            cout << a[i];
6        }
7        cout << "done";
8        cout <<"\n";
9    }
10    int equalPairs(vector<vector<int>>& grid) {
11        int m = grid.size();
12        int n = grid[0].size();
13        map<vector<int>, int> mp;
14
15        for(int i = 0; i < m; i++) {
16            vector<int> temp;
17            for(int j = 0; j < n; j++) {
18                temp.push_back(grid[i][j]);
19            }
20            mp[temp]++;
21            pri(temp);
22        }
23        int cnt = 0;
24
25        for(int i = 0; i < n; i++) {
26            vector<int> temp;
27            for(int j = 0; j < m; j++) {
28                temp.push_back(grid[j][i]);
29            }
30            if(mp.count(temp)) {
31                cnt += mp[temp];
32            }
33            pri(temp);
34        }
35
36        return cnt;
37
38    }
39};