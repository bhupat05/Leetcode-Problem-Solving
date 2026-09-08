// Last updated: 9/8/2026, 6:54:14 PM
1class Solution {
2public:
3    string reorganizeString(string s) {
4        int n = s.size();
5        vector<int> fre(26, 0);
6        for(char c : s) {
7            fre[c - 'a']++;
8        }
9        int mx = 0;
10        char c;
11
12        for(int i = 0; i < 26; i++) {
13            if(fre[i] > mx) {
14                mx = fre[i];
15                c = i + 'a';
16            }
17        }
18        if(mx > (n + 1) / 2) return "";
19        vector<int> ans(n, '#');
20        int l = 0;
21        while(mx--) {
22            ans[l] = c;
23            l += 2;
24            if(l >= n) l = 1;
25        }
26        for(int i = 0; i < 26; i++) {
27            if((i + 'a') == c) continue;
28
29            while(fre[i]--) {
30                ans[l] = i + 'a';
31                l += 2;
32                if(l >= n) l = 1;
33            }
34        }
35        string r = "";
36        for(char c : ans) {
37            r += string(1, c);
38        }
39        return r;
40    }
41};