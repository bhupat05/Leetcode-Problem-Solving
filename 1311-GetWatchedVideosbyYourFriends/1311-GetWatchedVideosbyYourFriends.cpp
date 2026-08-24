// Last updated: 8/24/2026, 11:06:05 AM
1class Solution {
2public:
3    unordered_map<string, int> mp;
4    void bfs(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level, vector<int>& vis) {
5        queue<int> q;
6        q.push(id);
7        vis[id] = 1;
8
9        while(!q.empty() && level > 0) {
10            int sz = q.size();
11
12            while(sz--) {
13                int u = q.front();
14                q.pop();
15
16                for(int v : friends[u]) {
17                    if(!vis[v]) {
18                        vis[v] = 1;
19                        q.push(v);
20                    }
21                }
22
23            }
24            level--;
25            
26        }
27
28        while(!q.empty()) {
29            int u = q.front();
30            q.pop();
31            for(string x : watchedVideos[u]) {
32                mp[x]++;
33            }
34        }
35    }
36    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
37        int n = watchedVideos.size();
38        vector<int> vis(n, 0);
39
40        bfs(watchedVideos, friends, id, level, vis);
41
42        vector<pair<int , string>> v;
43
44
45        for(auto [t, cnt] : mp) {
46            v.push_back({cnt, t});
47        }
48        sort(v.begin(), v.end());
49        vector<string> ans;
50
51        for(auto it : v) {
52            ans.push_back(it.second);
53        }
54        return ans;
55
56
57    }
58};