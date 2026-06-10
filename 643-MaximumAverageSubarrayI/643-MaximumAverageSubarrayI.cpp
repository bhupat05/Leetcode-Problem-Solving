// Last updated: 6/10/2026, 4:13:04 PM
1class Solution {
2public:
3    int maxOperations(vector<int>& nums, int k) {
4        sort(nums.begin(), nums.end());
5        int l = 0;
6        int r = nums.size() - 1;
7        int cnt = 0;
8        while(l < r) {
9            if(nums[l] + nums[r] == k) {
10                cnt++;
11                l++;
12                r--;
13            } else if(nums[l] + nums[r] > k) {
14                r--;
15            } else {
16                l++;
17            }
18        }
19        return cnt;
20    }
21};