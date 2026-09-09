// Last updated: 9/9/2026, 11:14:25 PM
1class Solution {
2public:
3    bool searchMatrix(vector<vector<int>>& matrix, int target) {
4        int m = matrix.size();
5        int n = matrix[0].size();
6        
7        int l = 0;
8        int r = n - 1;
9
10        while(l < m && r >= 0) {
11            if(matrix[l][r] == target) {
12                return true;
13            } else if(matrix[l][r] > target) {
14                r--;
15            } else {
16                l++;
17            }
18        }
19        return false;
20    }
21};