// Last updated: 8/23/2026, 6:53:11 PM
1class Solution {
2public:
3    bool sumGame(string num) {
4        int n = num.size();
5        int sum1 = 0;
6        int sum2 = 0;
7        int cnt1 = 0;
8        int cnt2 = 0;
9
10        for(int i = 0; i < n; i++) {
11            if(num[i] == '?') {
12                if(i < n / 2) {
13                    cnt1++;
14                } else {
15                    cnt2++;
16                }
17            } else {
18                if(i < n / 2) {
19                    sum1 += (num[i] - '0');
20                } else {
21                    sum2 += (num[i] - '0');
22                }
23            }
24        }
25
26        if(sum2 > sum1) {
27            swap(sum1, sum2);
28            swap(cnt1, cnt2);
29        }
30        if(cnt1 == cnt2) {
31            if(sum1 == sum2) return false;
32            else return true;
33        }
34
35        int d = sum1 - sum2;
36
37        int cnt = cnt1 - cnt2;
38
39        if(cnt > 0) {
40            return true;
41        } else {
42            cnt = -cnt;
43
44            int a = 0;
45            int b = 0;
46
47            if(cnt % 2 == 0) {
48                a = cnt / 2;
49                b = cnt / 2;
50            } else {
51                a = cnt / 2 + 1;
52                b = cnt / 2;
53            }
54
55            if((9 * a) > d) return true;
56            else if((9 * b) < d) return true;
57        }
58        return false;
59    }
60    
61};