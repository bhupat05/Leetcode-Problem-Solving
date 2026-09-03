// Last updated: 9/3/2026, 3:56:19 PM
1class Solution {
2public:
3    string longestWord(vector<string>& words) {
4        unordered_set<string> st(words.begin(), words.end());
5        sort(words.begin(), words.end(), [](const string &a, const string &b){return a.size() < b.size();});
6
7        int n = words.size();
8        int mx = 0;
9        string ans = "";
10        for(int i = n - 1; i >= 0; i--) {
11            string s = words[i];
12            mx = max(mx, (int)s.size());
13            int l = 0;
14            bool f = false;
15            for(int i = 0; i < s.size(); i++) {
16                if(!st.count(s.substr(l, i - l + 1))) f = true;
17            }
18            if(!f) {
19                if(ans == "") {
20                    ans = s;
21                } else {
22                    if(ans.size() == s.size() && ans > s) {
23                        ans = s;
24                    }
25                }
26            }
27        }
28        return ans;
29    }
30};