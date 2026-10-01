// Last updated: 10/1/2026, 10:57:19 AM
1class Solution {
2public:
3    bool isValid(string s) {
4        stack<char> st;
5
6        for (char c : s) {
7            if (c == '(') st.push(')');
8            else if (c == '{') st.push('}');
9            else if (c == '[') st.push(']');
10            else {
11                if (st.empty() || st.top() != c) return false;
12                st.pop();
13            }
14        }
15        return st.empty();
16    }
17};
18