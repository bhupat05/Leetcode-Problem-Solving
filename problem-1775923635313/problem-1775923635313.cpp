// Last updated: 4/11/2026, 9:37:15 PM
1class Solution {
2public:
3    int maxValue(vector<int>& nums1, vector<int>& nums0) {
4        int n = nums1.size();
5        int mod = 1e9 + 7;
6        priority_queue<pair<int, pair<int, int>>> pq;
7        priority_queue<pair<int, int>> pq2;
8
9        for(int i = 0; i < n; i++) {
10            if(nums0[i] == 0) {
11                pq2.push({nums1[i], i});
12            } 
13            else 
14            pq.push({(nums1[i]), {(-nums0[i]), i}});
15        }
16        string r = "";
17        while(!pq2.empty()) {
18            auto it = pq2.top();
19            pq2.pop();
20            int idx = it.second;
21            int a = nums1[idx];
22            r.append(a, '1');
23            
24        }
25        while(!pq.empty()) {
26            auto it = pq.top();
27            pq.pop();
28            
29            int d = it.first;
30            int idx = it.second.second;
31            
32            int a = nums1[idx];
33            int b = nums0[idx];
34            r.append(a, '1');
35            r.append(b, '0');
36            
37        }
38
39        int ans = 0;
40        int cnt = 1;
41
42        for(int i = r.size() - 1; i >= 0; i--) {
43            if(r[i] == '1') {
44                ans = (ans % mod+ cnt % mod) % mod;
45            }
46            cnt <<= 1;
47            cnt = cnt % mod;
48            
49        }
50        return ans;
51    }
52};