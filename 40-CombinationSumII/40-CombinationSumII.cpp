// Last updated: 7/10/2026, 7:25:01 AM
1class Solution {
2public:
3    vector<vector<int>> r;
4    int n;
5
6    void solve(vector<int>& candidates, int idx, int target, vector<int>& temp) {
7        if(idx == n) {
8            if(target == 0)
9            r.push_back(temp);
10            return;
11        }
12        if(target < 0) return;
13
14        temp.push_back(candidates[idx]);
15        solve(candidates, idx + 1, target - candidates[idx], temp);
16        temp.pop_back();
17        while(idx + 1 < n && candidates[idx] == candidates[idx + 1]) idx++;
18        solve(candidates, idx + 1, target, temp);
19    }
20    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
21        sort(candidates.begin(), candidates.end());
22        n = candidates.size();
23        vector<int> temp;
24        solve(candidates, 0, target, temp);
25        return r;
26    }
27};