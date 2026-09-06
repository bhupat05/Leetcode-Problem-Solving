// Last updated: 9/6/2026, 8:24:13 AM
1class Solution {
2public:
3    int countGoodRotations(vector<int>& nums) {
4        int n = nums.size();
5        int cnt = 0;
6        long long sum1 = 0;
7        long long sum2 = 0;
8        for(int i = 0; i < n / 2; i++) {
9            sum1 += nums[i];
10        }
11        for(int i = n / 2; i < n; i++) {
12            sum2 += nums[i];
13        }
14        // if(sum1 > sum2) cnt++;
15        int l = 0;
16        int r = n / 2;
17        while(r < n) {
18            sum1 -= nums[l];
19            sum1 += nums[r];
20            
21            sum2 += nums[l];
22            sum2 -= nums[r];
23            
24            if(sum1 > sum2) cnt++;
25            l++;
26            r++;
27        }
28        reverse(nums.begin(), nums.begin() + n / 2);
29        reverse(nums.begin() + n / 2, nums.end());
30        reverse(nums.begin(), nums.end());
31
32        l = 0;
33        r = n / 2;
34         while(r < n) {
35            sum1 -= nums[l];
36            sum1 += nums[r];
37            
38            sum2 += nums[l];
39            sum2 -= nums[r];
40            
41            if(sum1 > sum2) cnt++;
42            l++;
43            r++;
44        }
45        
46        return cnt;
47    }
48};