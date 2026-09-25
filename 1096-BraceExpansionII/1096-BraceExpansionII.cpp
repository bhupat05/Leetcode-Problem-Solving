// Last updated: 9/25/2026, 12:00:43 PM
1class Solution {
2public:
3
4    vector<string> merge(vector<string> a, vector<string> b, char c) {
5        vector<string> res;
6
7        if(c == '+') {
8            res = a;
9
10            for(string x : b) {
11                res.push_back(x);
12            }
13        }
14        else {
15            for(string x : a) {
16                for(string y : b) {
17                    res.push_back(x + y);
18                }
19            }
20        }
21
22        return res;
23    }
24
25    void apply(stack<vector<string>>& st, stack<char>& op) {
26
27        vector<string> b = st.top();
28        st.pop();
29
30        vector<string> a = st.top();
31        st.pop();
32
33        char c = op.top();
34        op.pop();
35
36        st.push(merge(a, b, c));
37    }
38
39    vector<string> braceExpansionII(string expression) {
40
41        stack<vector<string>> st;
42        stack<char> op;
43
44        bool prev = false;
45
46        for(int i = 0; i < expression.size(); i++) {
47
48            char c = expression[i];
49
50            if(c >= 'a' && c <= 'z') {
51
52                if(prev) {
53                    while(!op.empty() && op.top() == '*') {
54                        apply(st, op);
55                    }
56
57                    op.push('*');
58                }
59
60                st.push({string(1, c)});
61                prev = true;
62            }
63
64            else if(c == '{') {
65
66                if(prev) {
67                    while(!op.empty() && op.top() == '*') {
68                        apply(st, op);
69                    }
70
71                    op.push('*');
72                }
73
74                op.push('{');
75                prev = false;
76            }
77
78            else if(c == ',') {
79
80                while(!op.empty() && op.top() != '{') {
81                    apply(st, op);
82                }
83
84                op.push('+');
85                prev = false;
86            }
87
88            else if(c == '}') {
89
90                while(!op.empty() && op.top() != '{') {
91                    apply(st, op);
92                }
93
94                if(!op.empty() && op.top() == '{') {
95                    op.pop();
96                }
97
98                prev = true;
99            }
100        }
101
102        while(!op.empty()) {
103            apply(st, op);
104        }
105
106        set<string> s;
107
108        for(string x : st.top()) {
109            s.insert(x);
110        }
111
112        return vector<string>(s.begin(), s.end());
113    }
114};