// Last updated: 9/9/2026, 2:38:57 AM
1class Solution {
2public:
3    vector<int> findDuplicates(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> r;
6
7        for(int i = 0; i < n; i++) {
8            int x = abs(nums[i]);
9            int idx = x - 1;
10            if(nums[idx] < 0) {
11                r.push_back((idx + 1));
12            } else {
13                nums[x - 1] = -nums[x - 1];
14            }
15        }
16        return r;
17    }
18};