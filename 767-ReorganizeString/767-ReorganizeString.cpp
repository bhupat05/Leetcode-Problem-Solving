// Last updated: 9/8/2026, 3:08:48 PM
1class Solution {
2public:
3    string reorganizeString(string s) {
4        int n = s.size();
5        sort(s.begin(), s.end());
6        vector<pair<int, char>> arr;
7        int cnt = 1;
8        char curr = s[0];
9
10        for(int i = 1; i < n; i++) {
11            if(s[i] != s[i - 1]) {
12                arr.push_back({cnt, curr});
13                curr = s[i];
14                cnt = 1;
15            } else {
16                cnt++;
17            }
18        }
19        arr.push_back({cnt, curr});
20
21        sort(arr.rbegin(), arr.rend());
22
23        int l = 0;
24        vector<char> ans(n, '#');
25
26        for(auto[cnt, c] : arr) {
27            while(cnt--) {
28                ans[l] = c;
29                l += 2;
30                if(l >= n) {
31                    l = 1;
32                }
33            }
34        }
35        string r = string(1, ans[0]);
36        for(int i = 1; i < n; i++) {
37            if(ans[i] == r[i - 1] || ans[i] == '#') return "";
38            r += string(1, ans[i]);
39        }
40        return r;
41
42    }
43};