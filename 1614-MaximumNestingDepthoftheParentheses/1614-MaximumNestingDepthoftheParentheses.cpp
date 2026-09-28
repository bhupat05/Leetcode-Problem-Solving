// Last updated: 9/28/2026, 9:33:18 AM
1class Solution {
2public:
3    int maxDepth(string s) {
4        int ans = 0;
5        int cnt = 0;
6        stack<char> st;
7
8        for(char c : s) {
9            if(c == ')') {
10                st.pop();
11            } else if(c == '(') {
12                st.push(c);
13                ans = max(ans, (int)st.size());
14            }
15        }
16        return ans;
17    }
18};