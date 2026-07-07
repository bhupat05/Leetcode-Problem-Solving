// Last updated: 7/7/2026, 11:35:47 PM
1class Solution {
2public:
3    bool check(string &p, int j) {
4        
5        for(int i = 0; i <= j; i++) {
6            if(p[i] != '*') return false;
7        }
8        return true;
9        
10    }
11    bool solve(string &s, string &p, int i, int j, vector<vector<int>>& dp) {
12        if(i == -1 && j == -1) return true;
13        if(j == 0 && p[j] == '*') return true;
14        if(i == -1) {
15            return check(p, j);
16        }
17        if(j == -1) return false;
18
19        if(dp[i][j] != -1) return dp[i][j];
20
21        if((s[i] == p[j]) || (p[j] == '?')) {
22            return dp[i][j] = solve(s, p, i - 1, j - 1, dp);
23        } else if(p[j] == '*') {
24            
25            return dp[i][j] = solve(s, p, i - 1, j, dp) || solve(s, p, i, j - 1, dp);
26        } else {
27            return false;
28        }
29        return false;
30    }
31    bool isMatch(string s, string p) {
32        int m = s.size();
33        int n = p.size();
34        vector<vector<int>> dp(m, vector<int>(n, -1));
35        
36        return solve(s, p, m - 1, n - 1, dp);
37    }
38};