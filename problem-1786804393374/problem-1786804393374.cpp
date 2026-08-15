// Last updated: 8/15/2026, 8:03:13 PM
1class Solution {
2public:
3    int elevatorRequests(int n, vector<int>& requests) {
4        int m = requests.size();
5        int ans = 0;
6        int x = 0;
7
8        for(int i = 0; i < m; i++) {
9            ans += abs(requests[i] - x);
10            x = requests[i];
11        }
12        return ans;
13    }
14};