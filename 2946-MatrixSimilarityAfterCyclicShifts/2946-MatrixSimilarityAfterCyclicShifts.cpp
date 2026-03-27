// Last updated: 3/27/2026, 8:31:03 AM
1class Solution {
2public:
3    bool areSimilar(vector<vector<int>>& mat, int k) {
4        int m = mat.size();
5        int n = mat[0].size();
6        vector<vector<int>> v = mat;
7
8        k %= n;
9
10        for(int i = 0; i < m; i++) {
11            reverse(mat[i].begin(), mat[i].end());
12            if(i % 2 == 0) {
13                
14                reverse(mat[i].begin(), mat[i].begin() + (n - k));
15                reverse(mat[i].begin() + n - k, mat[i].end());
16            } else {
17                reverse(mat[i].begin(), mat[i].begin() + k);
18                reverse(mat[i].begin() + k, mat[i].end());
19            }
20        }
21
22
23        return mat == v;
24    }
25};