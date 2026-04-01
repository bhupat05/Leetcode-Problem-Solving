// Last updated: 4/1/2026, 10:17:55 AM
1class Solution {
2public:
3    vector<int> survivedRobotsHealths(vector<int>& a, vector<int>& b, string c) {
4        int n = a.size();
5        
6        vector<pair<int,int>> v; 
7        for(int i = 0; i < n; i++) {
8            v.push_back({a[i], i});
9        }
10
11        sort(v.begin(), v.end());
12
13        stack<int> st; 
14
15        for(auto &p : v) {
16            int i = p.second;
17
18            if(c[i] == 'R') {
19                st.push(i);
20            } else {
21                while(!st.empty() && b[i] > 0) {
22                    int j = st.top();
23
24                    if(b[j] < b[i]) {
25                        st.pop();
26                        b[i]--;
27                        b[j] = 0;
28                    } 
29                    else if(b[j] == b[i]) {
30                        st.pop();
31                        b[i] = 0;
32                        b[j] = 0;
33                        break;
34                    } 
35                    else {
36                        b[j]--;
37                        b[i] = 0;
38                        break;
39                    }
40                }
41            }
42        }
43
44        vector<int> result;
45        for(int i = 0; i < n; i++) {
46            if(b[i] > 0) result.push_back(b[i]);
47        }
48
49        return result;
50    }
51};