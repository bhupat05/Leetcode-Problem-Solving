// Last updated: 8/31/2026, 5:44:52 PM
1class Solution {
2public:
3    int gcd(int a, int b) {
4        return b == 0 ? a : gcd(b, a % b);
5    }
6    int maxValidSplits(vector<int>& nums) {
7        int n = nums.size();
8        int maxi = 0;
9
10        vector<int> p(n);
11        vector<int> s(n);
12        p[0] = nums[0];
13        s[n - 1] = nums[n - 1];
14        int cnt = 0;
15        for(int i = 1; i < n; i++) {
16            p[i] = gcd(p[i - 1], nums[i]);
17        }
18        for(int i = n - 2; i >= 0; i--) {
19            s[i] = gcd(s[i + 1], nums[i]);
20        }
21        for(int i = 0; i < n - 1; i++) {
22            if(p[i] == s[i + 1]) cnt++;
23        }
24        maxi = max(maxi, cnt);
25       
26
27        for(int i = 0; i < n; i++) {
28            vector<int> pre(n, 0);
29            vector<int> suff(n, 0);
30            int cnt = 0;
31            if(i != 0) pre[0] = nums[0];
32            if(i != n - 1) suff[n - 1] = nums[n - 1];
33    
34            for(int j = 1; j < n; j++) {
35              
36                if(i == j) pre[j] = pre[j - 1]; 
37                else {
38                    pre[j] = gcd(pre[j - 1], nums[j]);
39                }
40               
41            }
42            for(int j = n - 2; j >= 0; j--) {
43                
44                if(i == j) suff[j] = suff[j + 1]; 
45                else {
46                    suff[j] = gcd(suff[j + 1], nums[j]);
47                }
48                
49            }
50
51            for(int j = 0; j < n - 1; j++) {
52                if(pre[j] == suff[j + 1] && j != i) cnt++;
53            }
54            maxi = max(cnt, maxi);
55        }
56        return maxi;
57        
58    }
59};