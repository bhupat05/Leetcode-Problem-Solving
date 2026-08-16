// Last updated: 8/16/2026, 8:36:30 AM
1class Solution {
2public:
3    int bs(vector<int>& v, int x) {
4        int l = 0;
5        int r = v.size() - 1;
6
7        while(l <= r) {
8            int mid = l + (r - l) / 2;
9
10            if(v[mid] > x) {
11                return 0;
12            } else {
13                l = mid + 1;
14            }
15        }
16        return -1;
17    }
18    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
19        sort(lights.begin(), lights.end());
20        int n = arrivalTime.size();
21        for(int i = 0; i < n; i++) {
22            arrivalTime[i] = arrivalTime[i] % period;
23        }
24        int ans = INT_MIN;
25
26        for(int i = 0; i < n; i++) {
27            int x = bs(lights, arrivalTime[i]);
28            if(x == -1) {
29                x = period - arrivalTime[i];
30            }
31            ans = max(x, ans);
32        }
33        return ans;
34    }
35};