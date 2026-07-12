// Last updated: 7/12/2026, 8:30:47 AM
1class Solution {
2public:
3    int mod = 1e9 + 7;
4    int minimumCost(vector<int>& nums, int k) {
5        int n = nums.size();
6        long long cnt = 0;
7        long long x = 1;
8        long long f = k;
9
10        for(int i = 0; i < n; i++) {
11
12            
13            if(f < nums[i]) {
14                long long y = ((nums[i] - f + k - 1) / k) % mod;
15                long long a = 2 * x + y - 1;
16                long long b = y;
17                
18                if (a % 2 == 0)
19                    a /= 2;
20                else
21                    b /= 2;
22                
23                a %= mod;
24                b %= mod;
25                
26                cnt = (cnt + (a * b) % mod) % mod;
27                x += y;
28                f += y * 1LL * k;
29            }
30                
31            f -= nums[i];
32            
33        }
34        return cnt % mod;
35    }
36};