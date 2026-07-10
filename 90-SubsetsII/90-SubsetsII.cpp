// Last updated: 7/10/2026, 7:33:27 AM
1class Solution {
2public:
3    vector<vector<int>> r;
4    int n;
5    void solve(vector<int>& nums, int idx, vector<int>& temp) {
6        if(idx == n) {
7            r.push_back(temp);
8            return;
9        }
10
11        temp.push_back(nums[idx]);
12        solve(nums, idx + 1, temp);
13        temp.pop_back();
14        while(idx + 1 < n && nums[idx] == nums[idx + 1]) idx ++;
15        solve(nums, idx + 1, temp);
16    }
17    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
18        sort(nums.begin(), nums.end());
19        n = nums.size();
20        vector<int> temp;
21        solve(nums, 0, temp);
22        return r;
23    }
24};