// Last updated: 7/18/2026, 8:29:50 AM
1class Solution {
2public:
3    int findJudge(int n, vector<vector<int>>& trust) {
4        vector<vector<int>> adj(n + 1);
5        vector<int> in(n + 1, 0);
6        vector<int> out(n + 1, 0);
7
8        for(auto e : trust) {
9            adj[e[0]].push_back(e[1]);
10            in[e[1]]++;
11            out[e[0]]++;
12        }
13
14        
15        for(int i = 1; i <= n; i++) {
16            if(in[i] == n - 1 && out[i] == 0) return i; 
17        }
18        return -1;
19    }
20};