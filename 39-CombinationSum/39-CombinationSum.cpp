// Last updated: 7/10/2026, 7:10:29 AM
1class Solution {
2public:
3    vector<vector<int>> r;
4    int n;
5
6    void solve(vector<int>& candidates, int idx, int target, vector<int>& temp) {
7        if(idx == n) {
8            if(target == 0) {
9                r.push_back(temp);
10            }
11            return;
12        }
13        if(target < 0) return;
14
15        temp.push_back(candidates[idx]);
16        solve(candidates, idx, target - candidates[idx], temp);
17        temp.pop_back();
18        solve(candidates, idx + 1, target, temp);
19    }
20
21    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
22        n = candidates.size();
23        vector<int> temp;
24        solve(candidates, 0, target, temp);
25        return r;
26    }
27};