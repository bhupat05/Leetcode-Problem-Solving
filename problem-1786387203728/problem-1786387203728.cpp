// Last updated: 8/11/2026, 12:10:03 AM
1class Solution {
2public:
3    long long weightedSum(vector<int>& parent, vector<int>& nums) {
4       long long ans = 0;
5        int n = parent.size();
6
7        
8        vector<int> v(n, 0);
9        v[0] = 1;
10
11        unordered_map<int, vector<int>> mp;
12        for(int i = 0; i < parent.size(); i++) {
13            mp[parent[i]].push_back(i);
14        }
15
16        queue<int> q;
17        q.push(0);
18
19        while(!q.empty()) {
20            int x = q.front();
21            q.pop();
22            if(mp.count(x)) {
23                auto arr = mp[x];
24                for(int i : arr) {
25                    v[i] = v[x] + 1;
26                    q.push(i);
27                }
28            }
29        }
30        int maxi = 1;
31        for(int i = 0; i < n; i++) {
32            maxi = max(maxi, v[i]);
33        }
34
35        for(int i = 0; i < n; i++) {
36            ans += 1L * (nums[i] * 1L * (maxi - v[i] + 1));
37        }
38        return ans;
39    }
40};