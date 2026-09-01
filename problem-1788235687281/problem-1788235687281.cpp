// Last updated: 9/1/2026, 9:38:07 AM
1class Solution {
2public:
3    long long mod = 1e9 + 7;
4    long long pow(long long a, long long b) {
5        long long r = 1;
6        a = (a % mod + mod) % mod;
7
8        while(b > 0) {
9            if(b % 2 == 1) {
10                r = (r * a) % mod;
11            }
12            a = ((1LL * a) * a) % mod;
13            b = b / 2;
14        }
15        cout << r;
16        return r;
17    }
18    long long rev(long long d) {
19        long long y = 0;
20        while(d > 0) {
21            y = y * 10 + (d % 10);
22            d = d / 10;
23            
24        }
25        return y;
26    }
27    int sumDecoded(vector<long long>& nums) {
28        int n = nums.size();
29        long long ans = 0;
30
31        for(int i = 0; i < n; i++) {
32            int w = nums[i] % 10;
33            long long d = nums[i] / 10;
34            long long nd = rev(d);
35            int cnt = 0;
36            while(d > 0) {
37                cnt++;
38                d = d / 10;
39            }
40            cnt = cnt - w;
41            long long a = 0;
42            while(w--) {
43                a = (a * 10) + (nd % 10);
44                
45                nd = nd / 10;
46            }
47            long long b = 0;
48
49            while(cnt--) {
50                b = (b * 10) + (nd % 10);
51                nd = nd / 10;
52            }
53            cout << a << " " << b << endl;
54
55            ans = (ans + pow(1LL * a, 1LL * b)) % mod;
56        }
57        return ans;
58        
59    }
60};