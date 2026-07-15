// Last updated: 7/15/2026, 7:48:51 AM
1class Solution {
2public:
3    int findLongestChain(vector<vector<int>>& pairs) {
4        sort(pairs.begin(), pairs.end(), [](const vector<int> &a, const vector<int> &b){
5            return a[1] < b[1];
6        });
7
8        int last = INT_MIN;
9        int ans = 0;
10        for(auto &p : pairs) {
11            if(p[0] > last) {
12                ans++;
13                last = p[1];
14            }
15        }
16        return ans;
17    }
18};