// Last updated: 4/22/2026, 10:03:27 AM
1class Solution {
2public:
3    bool isValid(string &q, string &d) {
4        int diff = 0;
5        for(int i = 0; i < q.size(); i++) {
6            if(q[i] != d[i]) diff++;
7            if(diff > 2) return false;
8        }
9        return true;
10    }
11
12    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
13        vector<string> res;
14
15        for(string &q : queries) {
16            for(string &d : dictionary) {
17                if(isValid(q, d)) {
18                    res.push_back(q);
19                    break; 
20                }
21            }
22        }
23
24        return res;
25    }
26};