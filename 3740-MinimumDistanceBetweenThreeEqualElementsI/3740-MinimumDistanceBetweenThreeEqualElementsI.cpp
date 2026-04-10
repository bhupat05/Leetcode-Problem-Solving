// Last updated: 4/10/2026, 9:33:54 AM
1class Solution {
2public:
3    int minimumDistance(vector<int>& nums) {
4        int n = nums.size();
5        int ans = INT_MAX;
6        int curr = -1;
7
8        for(int i = 0; i < n; i++) {
9            for(int j = i + 1; j < n; j++) {
10                for(int k = j + 1; k < n; k++) {
11                    if(nums[i] == nums[j] && nums[k] == nums[j]) {
12                        curr = abs(i - j) + abs(j - k) + abs(i - k);
13                        ans = min(ans, curr);
14                    }
15                }
16            }
17        }
18
19        return min(ans, curr);
20    }
21};