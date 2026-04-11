// Last updated: 4/11/2026, 8:19:17 PM
1class Solution {
2public:
3    bool prime(int d) {
4        if(d <= 1) return false;
5        for(int i = 2; i * i <= d; i++) {
6            if(d % i == 0) return false;
7        }
8        return true;
9    }
10    int minOperations(vector<int>& nums) {
11        int n = nums.size();
12        int ans = INT_MAX;
13        int cnt = 0;
14        for(int i = 0; i < n; i++) {
15            int d = nums[i];
16
17            if(i % 2 == 0) {
18                while(!prime(d)) {
19                    d++;
20                    cnt++;
21                }
22            } else {
23                while(prime(d)) {
24                    d++;
25                    cnt++;
26                }
27            }
28        }
29        
30      
31        return min(cnt, ans);
32        
33    }
34};