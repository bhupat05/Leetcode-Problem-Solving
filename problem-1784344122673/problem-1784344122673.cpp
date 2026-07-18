// Last updated: 7/18/2026, 8:38:42 AM
1class Solution {
2public:
3    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
4        vector<int> result;
5        vector<int> in(n + 1, 0);
6        for(auto e : edges) {
7            in[e[1]]++;
8        }   
9        for(int i = 0; i < n; i++) {
10            if(in[i] == 0) {
11                result.push_back(i);
12            }
13        }
14        return result;
15    }
16};