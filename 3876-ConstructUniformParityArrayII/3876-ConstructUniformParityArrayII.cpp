// Last updated: 9/3/2026, 10:26:23 AM
1class Solution {
2public:
3    bool uniformArray(vector<int>& nums1) {
4        int n = nums1.size();
5        int odd = 0;
6        int even = 0;
7        vector<int> mno(n, -1);
8        vector<int> mnro(n, -1);
9        int rodd = 0;
10        for(int i = n - 1; i >= 0; i--) {
11            if(nums1[i] % 2 == 1) {
12                if(rodd == 0) {
13                    mnro[i] = nums1[i];
14                } else {
15                    mnro[i] = min(mnro[i + 1], nums1[i]);
16                }
17                rodd++;
18            } else {
19                if(i + 1 < n) mnro[i] = mnro[i + 1];
20            }
21        }
22
23        for(int i = 0; i < n; i++) {
24            if(nums1[i] % 2 == 0) {
25                even++;
26                if(i > 0) mno[i] = mno[i - 1];
27            } else {
28                if(odd == 0) {
29                    mno[i] = nums1[i];
30                } else {
31                    mno[i] = min(mno[i - 1], nums1[i]);
32                }
33                odd++;
34            }
35
36        }
37       
38        if((even == n) || (odd == n)) return true;
39
40        for(int i = 0; i < n; i++) {
41            int x = INT_MAX;
42            if(mno[i] != -1) {
43                x = min(x, mno[i]);
44            }
45            if(mnro[i] != -1) {
46                x = min(x, mnro[i]);
47            }
48            if(nums1[i] % 2 == 1) {
49                if(x != INT_MAX) {
50                    if(nums1[i] - x >= 1) odd--;
51                }
52            } else {
53                 if(x != INT_MAX) {
54                    if(nums1[i] - x >= 1) even--;
55                }
56            }
57        }
58        
59        return (odd <= 0) || ( even <= 0);
60    }
61};