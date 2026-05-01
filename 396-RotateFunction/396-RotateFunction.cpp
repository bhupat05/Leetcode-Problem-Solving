// Last updated: 5/1/2026, 2:53:20 PM
1class Solution {
2public:
3    int maxRotateFunction(vector<int>& nums) {
4        int n = nums.size();
5        
6        long long totalSum = 0;
7        long long F = 0;
8        
9        for (int i = 0; i < n; i++) {
10            totalSum += nums[i];
11            F += (long long)i * nums[i];
12        }
13        
14        long long maxVal = F;
15        
16        for (int k = 1; k < n; k++) {
17            F = F + totalSum - (long long)n * nums[n - k];
18            maxVal = max(maxVal, F);
19        }
20        
21        return (int)maxVal;
22    }
23};