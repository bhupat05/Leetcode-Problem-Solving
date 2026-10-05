// Last updated: 10/5/2026, 12:34:06 PM
1class Solution {
2public:
3    int scoreOfParentheses(string s) {
4        stack<int> st;
5
6        for (char c : s) {
7
8            if (c == '(') {
9                st.push(0);
10            }
11            else {
12                int sum = 0;
13
14                while (st.top() != 0) {
15                    sum += st.top();
16                    st.pop();
17                }
18
19                st.pop();  
20
21                if (sum == 0)
22                    st.push(1);       
23                else
24                    st.push(2 * sum); 
25            }
26        }
27
28        int ans = 0;
29
30        while (!st.empty()) {
31            ans += st.top();
32            st.pop();
33        }
34
35        return ans;
36    }
37};