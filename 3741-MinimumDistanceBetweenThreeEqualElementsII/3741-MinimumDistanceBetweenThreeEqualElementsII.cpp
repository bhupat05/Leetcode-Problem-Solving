// Last updated: 4/11/2026, 10:52:53 AM
1class Solution {
2public:
3    int minimumDistance(vector<int>& nums) {
4        unordered_map<int, vector<int>> mp;
5
6        for (int i = 0; i < nums.size(); i++) {
7            mp[nums[i]].push_back(i);
8        }
9
10        int mini = INT_MAX;
11
12        for (auto &p : mp) {
13            vector<int> &v = p.second;
14
15            if (v.size() < 3) continue;
16
17            for (int i = 0; i + 2 < v.size(); i++) {
18                int d = 2 * (v[i + 2] - v[i]);
19                mini = min(mini, d);
20            }
21        }
22
23        return mini == INT_MAX ? -1 : mini;
24    }
25};