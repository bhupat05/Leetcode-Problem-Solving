// Last updated: 8/11/2026, 7:10:01 PM
1class Solution {
2public:
3    
4    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
5        int m = series1.size();
6        int n = series2.size();
7
8        vector<vector<int>> ans;
9        
10        int i = 0;
11        int j = 0;
12        while(i < m && j < n) {
13            int sum = 0;
14            if(series1[i][0] == series2[j][0]) {
15                sum += series1[i][1] + series2[j][1];
16                ans.push_back({series1[i][0], sum});
17                i++; 
18                j++;
19            }
20            else if(series1[i][0] < series2[j][0]) {
21                sum += series1[i][1] + series2[j][1];
22                ans.push_back({series1[i][0], sum});
23                i++; 
24            } else {
25                sum += series1[i][1] + series2[j][1];
26                ans.push_back({series2[j][0], sum});
27                 j++;
28            }
29        }
30
31        while(i < m) {
32            ans.push_back({series1[i][0], series1[i][1]});
33            i++;
34        }
35
36        while(j < n) {
37            ans.push_back({series2[j][0], series2[j][1]});
38            j++;
39        }
40        return ans;
41    }
42};