// Last updated: 9/3/2026, 10:03:14 PM
1class Solution {
2public:
3    vector<int> findSubstring(string s, vector<string>& words) {
4        int n = s.size();
5        int m = words[0].size();
6        unordered_map<string, int> mp;
7        vector<int> ans;
8
9        for(string &t : words) {
10            mp[t]++;
11        }
12        int req = words.size();
13
14        for(int j = 0; j < m; j++) {
15            int l = j;
16            int cnt = 0;
17            unordered_map<string, int> temp;
18
19            for(int i = j; i + m <= n; i += m) {
20                string t = s.substr(i, m);
21                if(mp.count(t)) {
22                    cnt++;
23                    temp[t]++;
24
25                    while(req <= cnt) {
26                        if(temp == mp) {
27                            ans.push_back(l);
28                        }
29                        temp[s.substr(l, m)]--;
30                        if(temp[s.substr(l, m)] == 0) {
31                            temp.erase(s.substr(l, m));
32                        }
33                        l += m;
34                        cnt--;
35                    }
36                } else {
37                    l = i + m;
38                    temp.clear();
39                    cnt = 0;
40                }
41                
42            }
43        }
44        return ans;
45    }
46};