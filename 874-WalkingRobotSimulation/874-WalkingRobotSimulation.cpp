// Last updated: 4/7/2026, 9:01:09 AM
1class Robot {
2public:
3    int x = 0;
4    int y = 0;
5    int d = 1;
6    int w;
7    int h;
8
9    Robot(int width, int height) {
10        w = width;
11        h = height;
12    }
13    
14    void step(int n) {
15        int mod = 2 * (w + h - 2);   
16        n %= mod;     
17         if(n == 0) n = mod;               
18
19        while(n > 0) {
20            if(d == 1) {
21                int dis = w - x - 1;
22                if(dis >= n) {
23                    x += n;
24                    n = 0;
25                } else {
26                    x += dis;
27                    n -= dis;
28                    d = (d + 3) % 4;
29                }
30            } 
31            else if(d == 0) {
32                int dis = h - y - 1;
33                if(dis >= n) {
34                    y += n;
35                    n = 0;
36                } else {
37                    y += dis;
38                    n -= dis;
39                    d = (d + 3) % 4;
40                }
41            } 
42            else if(d == 3) {
43                int dis = x;
44                if(dis >= n) {
45                    x -= n;
46                    n = 0;
47                } else {
48                    x -= dis;
49                    n -= dis;
50                    d = (d + 3) % 4;
51                }
52            } 
53            else {
54                int dis = y;
55                if(dis >= n) {
56                    y -= n;
57                    n = 0;
58                } else {
59                    y -= dis;
60                    n -= dis;
61                    d = (d + 3) % 4;
62                }
63            }
64        }
65    }
66    
67    vector<int> getPos() {
68        return {x, y};
69    }
70    
71    string getDir() {
72        if(d == 0) return "North";
73        else if(d == 1) return "East";
74        else if(d == 2) return "South";
75        else return "West";
76    }
77};
78
79/**
80 * Your Robot object will be instantiated and called as such:
81 * Robot* obj = new Robot(width, height);
82 * obj->step(num);
83 * vector<int> param_2 = obj->getPos();
84 * string param_3 = obj->getDir();
85 */