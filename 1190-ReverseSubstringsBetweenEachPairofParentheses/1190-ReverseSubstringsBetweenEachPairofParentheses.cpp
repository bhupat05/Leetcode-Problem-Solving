// Last updated: 9/27/2026, 10:41:45 AM
1class Solution {
2public:
3    string reverseParentheses(string s) {
4        string r = "";
5        stack<char> st;
6
7        for(char c : s) {
8            if(c == ')') {
9                string curr = "";
10                while(!st.empty() && st.top() != '(') {
11                    curr += st.top();
12                    st.pop();
13                }
14                if(!st.empty()) st.pop();
15                for(char ch : curr) {
16                    st.push(ch);
17                }
18            } else {
19                st.push(c);
20            }
21        }
22        while(!st.empty()) {
23            r += st.top();
24            st.pop();
25        }
26        reverse(r.begin(), r.end());
27        return r;
28    }
29};