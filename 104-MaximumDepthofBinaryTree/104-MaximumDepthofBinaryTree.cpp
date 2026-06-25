// Last updated: 6/25/2026, 5:18:30 PM
1class Solution {
2public:
3    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
4        int n = intervals.size();
5        sort(intervals.begin(), intervals.end());
6        for(auto it : intervals) {
7            cout << it[0] <<" " << it[1] << "\n";
8        }
9        int cnt = 0;
10        int l = 0;
11        int r = 0;
12        
13        for(int i = 1; i < n; i++) {
14            if(intervals[l][1] > intervals[i][0]) cnt++;
15            else l = i;
16        }
17        r = cnt;
18        cnt = 0;
19        l = n - 1;
20
21         for(int i = n - 2; i >= 0; i--) {
22            if(intervals[l][0] < intervals[i][1]) cnt++;
23            else l = i;
24        }
25
26        return min(r, cnt);
27    }
28};