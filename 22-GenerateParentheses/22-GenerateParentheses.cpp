// Last updated: 7/10/2026, 9:50:15 AM
1class Solution {
2public:
3    vector<string> ans;
4    void solve(int n, int l, int r, string& s) {
5        if(l == n && r == n) {
6            ans.push_back(s);
7            return;
8        }
9
10        if(l < n) {
11            s.push_back('(');
12            solve(n, l + 1, r, s);
13            s.pop_back();
14        }
15        
16
17
18        if(l > r) {
19             s.push_back(')');;
20            solve(n, l, r + 1, s);
21            s.pop_back();
22        }
23    }
24    vector<string> generateParenthesis(int n) {
25        if(n == 0) return {""};
26        string s;
27       
28        solve(n, 0, 0, s);
29        return ans;
30    }
31};