// Last updated: 7/10/2026, 7:02:33 AM
1class Solution {
2public:
3    vector<vector<int>> r;
4    void solve(vector<int>&nums, int idx, vector<int>& temp) {
5        if(idx == nums.size()) {
6            r.push_back(temp);
7            return;
8        }
9
10        temp.push_back(nums[idx]);
11        solve(nums, idx + 1, temp);
12        temp.pop_back();
13        solve(nums, idx + 1, temp);
14    }
15    vector<vector<int>> subsets(vector<int>& nums) {
16        int n = nums.size();
17        vector<int> temp;
18        solve(nums, 0, temp);
19
20        return r;
21    }
22};