// Last updated: 11/6/2026, 2:13:15 PM
1class Solution {
2public:
3    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
4        vector<int> result(queries.size());
5
6        sort(logs.begin(), logs.end(), [](auto& a, auto& b) {
7            return a[1] < b[1];
8        });
9
10        vector<vector<int>> v;
11        for(int i = 0; i < queries.size(); i++) {
12            v.push_back({queries[i], i});
13        }
14
15        sort(v.begin(), v.end());
16
17        vector<int> freq(n + 1, 0);
18        int zero = n;
19
20        int l = 0, r = 0;
21
22        for(auto& it : v) {
23            int y = it[0];
24            int idx = it[1];
25
26            while(r < logs.size() && logs[r][1] <= y) {
27                int server = logs[r][0];
28
29                if(freq[server] == 0) zero--;
30                freq[server]++;
31
32                r++;
33            }
34
35            while(l < r && logs[l][1] < y - x) {
36                int server = logs[l][0];
37
38                freq[server]--;
39                if(freq[server] == 0) zero++;
40
41                l++;
42            }
43
44            result[idx] = zero;
45        }
46
47        return result;
48    }
49};