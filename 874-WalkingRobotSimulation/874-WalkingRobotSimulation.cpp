// Last updated: 4/6/2026, 9:15:47 AM
1class Solution {
2public:
3    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
4        int n = commands.size();   
5        set<pair<int, int>> st;
6
7        for (auto &v : obstacles) {
8            st.insert({v[0], v[1]});
9        }
10        
11
12        int x = 0;
13        int y = 0;
14        int dis = 0;
15        int d= 0;
16
17        for(int it : commands) {
18            if(it == -1) {
19                d = (d + 1) % 4;
20            } else if(it == -2) {
21                d = (d + 3) % 4;
22            } else {
23                if(d == 0) {
24                    while(it-- && !st.count({x, y + 1})) {
25                        y++;
26                    }
27                } else if(d == 1) {
28                    while(it-- && !st.count({x + 1, y})) {
29                        x++;
30                    }
31                } else if(d == 2) {
32                    while(it-- && !st.count({x, y - 1})) {
33                        y--;
34                    }
35                } else {
36                     while(it-- && !st.count({x - 1, y})) {
37                        x--;
38                    }
39                }
40                
41            }   
42            dis = max(dis, (x * x + y * y));
43
44        }
45        return dis;
46    }
47};