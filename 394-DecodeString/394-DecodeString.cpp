// Last updated: 6/27/2026, 7:18:56 PM
1class Solution {
2public:
3    string decodeString(string s) {
4        int n = s.size();
5        stack<char> st;
6        string r = "";
7        
8        for(int i = 0; i < n; i++) {
9            if(s[i] == ']') {
10                string temp = "";
11                int cnt = 0;
12
13                while(!st.empty() && st.top() != '[') {
14                    temp += st.top();
15                    st.pop();
16                }
17                reverse(temp.begin(), temp.end());
18                st.pop();
19                string te = "";
20                while(!st.empty() && isdigit(st.top())) {
21                    te += st.top();
22                    st.pop();
23                }
24                reverse(te.begin(), te.end());
25                cnt = stoi(te);
26            
27                string t = "";
28
29                for(int i = 0; i < cnt; i++) {
30                    t += temp;
31                }
32                
33                for(int j = 0; j < t.size(); j++) {
34                    st.push(t[j]);
35                }
36
37
38            } else {
39                st.push(s[i]);
40            }
41        }
42
43        while(!st.empty()) {
44            r += st.top();
45            st.pop();
46        }
47        reverse(r.begin(), r.end());
48        return r;
49    }
50};