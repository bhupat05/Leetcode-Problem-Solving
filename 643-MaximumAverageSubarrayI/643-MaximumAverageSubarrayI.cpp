// Last updated: 6/10/2026, 5:02:45 PM
1class Solution {
2public:
3    int longestOnes(vector<int>& nums, int k) {
4        int n = nums.size();
5        int l = 0;
6        int ans = 0;
7        int zero = 0;
8
9        for(int i = 0; i < n; i++) {
10            if(nums[i] == 0) zero++;
11
12            while(zero > k) {
13                if(nums[l] == 0) zero--;
14                l++;
15            }
16            ans = max(ans, i - l + 1);
17        }   
18        return ans;
19    }
20};