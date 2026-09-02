// Last updated: 9/2/2026, 7:04:53 PM
1class Solution {
2public:
3    int minLights(vector<int>& lights) {
4        int n = lights.size();
5        vector<int> arr(n + 1, 0);
6
7        for(int i = 0; i < n; i++) {
8            int v = lights[i];
9            if(v > 0) {
10                if(i - v >= 0) {
11                    arr[i - v] += 1;
12                } else {
13                    arr[0] += 1;
14                }
15                if(i + v < n) {
16                    arr[i + v + 1] -= 1; 
17                } else {
18                    arr[n] -= 1;
19                }
20            }
21        }
22        for(int i = 1; i <= n; i++) {
23            arr[i] += arr[i - 1];
24        }
25
26        
27
28        int ans = 0;
29        int cnt = 1;
30        for(int j = 1; j < n; j++) {
31            if(arr[j] != arr[j - 1]) {
32                if(arr[j - 1] == 0) {
33                    if((cnt % 3) && (cnt <= 3)) {
34                        ans++;
35                        
36                    } else {
37                        if(cnt % 3) {
38                            ans++;
39                        }
40                        ans += (cnt / 3);
41                    }
42                    
43                }
44                cnt = 1;
45            } else {
46                cnt++;
47            }
48        }
49
50        if(arr[n - 1] == 0) {
51            if((cnt % 3) && (cnt < 3)) {
52            ans++;
53            
54        } else {
55            if(cnt % 3) {
56                ans++;
57            }
58            ans += (cnt / 3);
59        }
60        }
61        
62           
63        return ans;
64    }
65};