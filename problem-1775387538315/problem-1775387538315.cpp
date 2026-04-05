// Last updated: 4/5/2026, 4:42:18 PM
1class Solution {
2public:
3    unordered_set<string> st;
4    int cnt = 0;
5    int bfs(string end) {
6        queue<pair<string, int>> q;
7        q.push({"0000", 0});
8        
9
10        while(!q.empty()) {
11            int sz = q.size();
12
13            while(sz--) {
14                auto[nd, level] = q.front();
15                q.pop();
16
17                cout << nd << "->" << level << " ";
18
19                if(nd == end) {
20                    return level;
21                }
22
23
24                for(int i = 0; i < 4; i++) {
25                    char x = nd[i];
26                    if(nd[i] + 1 <= '9') {
27                        nd[i] += 1;
28                    }
29                    
30                    if(!st.count(nd)) {
31                        q.push({nd, level + 1});
32                        st.insert(nd);
33                    }
34
35                    nd[i] = x;  
36                    if(nd[i] == '0') {
37                        nd[i] = '9' - (nd[i] - '0');
38                    } else if(nd[i] - 1 >= '0'){
39                        nd[i] -= 1;
40                    }
41                    if(!st.count(nd)) {
42                        q.push({nd, level + 1});
43                        st.insert(nd);
44                    }
45                   nd[i] = x;    
46                }
47            }
48        }
49        return -1;
50    }
51    int openLock(vector<string>& deadends, string end) {
52        for(auto str : deadends) {
53            st.insert(str);
54        }
55
56       if(st.count("0000")) return -1;
57
58        return bfs(end);
59    }
60};