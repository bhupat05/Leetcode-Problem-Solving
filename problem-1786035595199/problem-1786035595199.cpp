// Last updated: 8/6/2026, 10:29:55 PM
1class Solution {
2public:
3    long long gcd(int a, int b) {
4        return b == 0 ? a : gcd(b, a % b);
5    }
6    long long maxPairStrength(vector<int>& nums) {
7        int n = nums.size();
8        long long ans = 0;
9
10        for(int i = 0; i < n; i++) {
11            for(int j = i + 1; j < n; j++) {
12                long long y = gcd(nums[i], nums[j]);
13                long long x = nums[i] / y;
14                x *= nums[j] / y;
15                
16                ans = max(ans, x);
17            }
18        }
19        return ans;
20    }
21};