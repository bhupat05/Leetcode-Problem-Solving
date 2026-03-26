// Last updated: 3/26/2026, 4:32:56 PM
1class Solution {
2public:
3    string simplifyPath(string path) {
4        stack<string> st;
5        string curr = "";
6
7        for(int i = 0; i <= path.size(); i++) {
8            if(i == path.size() || path[i] == '/') {
9                
10                if(curr == "" || curr == ".") {
11                    // do nothing
12                } 
13                else if(curr == "..") {
14                    if(!st.empty()) st.pop();
15                } 
16                else {
17                    st.push(curr);
18                }
19
20                curr = "";
21            } 
22            else {
23                curr += path[i];
24            }
25        }
26
27        string res = "";
28        while(!st.empty()) {
29            res = "/" + st.top() + res;
30            st.pop();
31        }
32
33        return res.empty() ? "/" : res;
34    }
35};