// Last updated: 7/10/2026, 7:29:14 AM
1class Solution {
2public:
3    vector<vector<int>> r;
4    int n;
5    
6    void solve(vector<int>& nums, int idx) {
7        if(idx == n) {
8            r.push_back(nums);
9            return;
10        }
11        for(int i = idx; i < n; i++) {
12            swap(nums[idx], nums[i]);
13            solve(nums, idx + 1);
14            swap(nums[idx], nums[i]);
15        }
16    }
17
18    vector<vector<int>> permute(vector<int>& nums) {
19        n = nums.size();
20        solve(nums, 0);
21        return r;
22    }
23};