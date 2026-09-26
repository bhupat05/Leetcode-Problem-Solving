// Last updated: 9/26/2026, 9:56:14 AM
1class Solution {
2public:
3    string evaluate(string s, vector<vector<string>>& knowledge) {
4        string r = "";
5        unordered_map<string, string> mp;
6        for(int i = 0; i < knowledge.size(); i++) {
7            mp[knowledge[i][0]] = knowledge[i][1];
8        }
9
10        string curr = "";
11        bool f = false;
12
13        for(int i = 0; i < s.size(); i++) {
14            if(s[i] == '(') {
15                f = true;
16            } else if(s[i] == ')') {
17                f = false;
18                if(mp.count(curr)) {
19                    r += mp[curr];
20                    curr = "";
21                } else {
22                    r += '?';
23                    curr = "";
24                }
25            } else {
26                if(f) {
27                    curr += s[i];
28                } else {
29                    r += s[i];
30                }
31            }
32        }
33        return r;
34    }
35};