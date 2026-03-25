// Last updated: 3/26/2026, 1:23:59 AM
1class Solution {
2public:
3    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
4        int i = 0;
5        vector<vector<int>> result;
6        int n = intervals.size();
7
8        while(i < n){
9            if(intervals[i][1] < newInterval[0]){
10                result.push_back(intervals[i]);
11            }else if(intervals[i][0] > newInterval[1]){
12                break;
13            }else{
14                newInterval[0] = min(newInterval[0], intervals[i][0]);
15                newInterval[1] = max(newInterval[1], intervals[i][1]);
16            }
17            i++;
18        }
19        result.push_back(newInterval);
20        while(i < n){
21            result.push_back(intervals[i]);
22            i++;
23        }
24        return result;
25    }
26};