// Last updated: 6/21/2026, 11:30:47 AM
1class Solution {
2public:
3    vector<int> asteroidCollision(vector<int>& asteroids) {
4        int n = asteroids.size();
5        vector<int> r;
6        stack<int> st;
7        bool f = false;
8
9        for(int x : asteroids) {
10            if(x < 0) {
11                if(st.empty() || st.top() < 0) {
12                    st.push(x);
13                } else {
14                    while(!st.empty() && abs(x) >= st.top()) {
15                        
16                        if(st.top() < 0) {
17                            st.push(x);
18                            break;
19                        }
20
21                        else {
22                            if(abs(x) == st.top()) {
23                            f = true;
24                            st.pop();
25                            break;
26                            
27                            } else {
28                                st.pop();
29                            }
30                        }
31                       
32                        
33                    }
34                    if(st.empty() && !f) {
35                        st.push(x);
36                        
37                    }
38                }
39                f = false;
40            } else {
41                st.push(x);
42            }
43        }
44
45        while(!st.empty()) {
46            int curr = st.top();
47            st.pop();
48            r.push_back(curr);
49        }
50        reverse(r.begin(), r.end());
51        return r;
52    }
53};