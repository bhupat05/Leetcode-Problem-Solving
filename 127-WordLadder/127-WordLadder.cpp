// Last updated: 4/5/2026, 3:08:57 PM
1class Solution {
2public:
3    unordered_set<string> st;
4    int cnt = 1;
5
6    int bfs(string start, string end) {
7        queue<string> q;
8        q.push(start);
9
10        while(!q.empty()) {
11            int sz = q.size();
12
13            while(sz--) {
14                string nd = q.front();
15                q.pop();
16
17                if(nd == end) {
18                    return cnt;
19                }
20
21                for(int i = 0; i < nd.size(); i++) {
22                    char x = nd[i];
23                    for(char c = 'a'; c <= 'z'; c++) {
24                        nd[i] = c;
25
26                        if(st.count(nd)){
27                            q.push(nd);
28                            st.erase(nd);
29                            
30                        }
31                    }
32                    nd[i] = x;
33                }
34            }
35            cnt++;
36        }
37        return 0;
38    }
39
40    int ladderLength(string start, string end, vector<string>& wordList) {
41        for(auto str : wordList) {
42            st.insert(str);
43        }
44        if(!st.count(end)) return 0;
45
46        return bfs(start, end);
47    }
48};