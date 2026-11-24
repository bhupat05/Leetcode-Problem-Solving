// Last updated: 11/24/2026, 10:23:48 PM
1class Solution {
2public:
3    int maxLength(vector<int>& nums) {
4        int res = 0;
5        for (int i = 0; i < nums.size(); i++) {
6            long long prodVal = nums[i];
7            long long gcdVal = nums[i];
8            long long lcmVal = nums[i];
9            for (int j = i + 1; j < nums.size(); j++) {
10                prodVal = prodVal * nums[j];
11                gcdVal = gcd(gcdVal, nums[j]);
12                lcmVal = lcm(lcmVal, nums[j]);
13                if (prodVal > gcdVal * lcmVal) {
14                    break;
15                }
16                if (prodVal == gcdVal * lcmVal) {
17                    res = max(res, j - i + 1);
18                }
19            }
20        }
21
22        return res;
23    }
24};