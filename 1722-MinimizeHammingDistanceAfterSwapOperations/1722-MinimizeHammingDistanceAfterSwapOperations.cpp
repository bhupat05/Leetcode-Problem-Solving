// Last updated: 4/21/2026, 12:54:16 PM
1#include <bits/stdc++.h>
2using namespace std;
3
4class Solution {
5public:
6    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& comp) {
7        visited[node] = true;
8        comp.push_back(node);
9
10        for (int nei : graph[node]) {
11            if (!visited[nei]) {
12                dfs(nei, graph, visited, comp);
13            }
14        }
15    }
16
17    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
18        int n = source.size();
19
20        vector<vector<int>> graph(n);
21        for (auto &edge : allowedSwaps) {
22            int u = edge[0], v = edge[1];
23            graph[u].push_back(v);
24            graph[v].push_back(u);
25        }
26
27        vector<bool> visited(n, false);
28        int ans = 0;
29
30        for (int i = 0; i < n; i++) {
31            if (!visited[i]) {
32                vector<int> comp;
33                dfs(i, graph, visited, comp);
34
35                unordered_map<int, int> freq;
36                for (int idx : comp) {
37                    freq[source[idx]]++;
38                }
39
40                for (int idx : comp) {
41                    if (freq[target[idx]] > 0) {
42                        freq[target[idx]]--;
43                    } else {
44                        ans++; 
45                    }
46                }
47            }
48        }
49
50        return ans;
51    }
52};