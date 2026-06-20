// Last updated: 6/20/2026, 12:44:44 PM
1class Solution {
2public:
3    int compress(vector<char>& chars) {
4        int n = chars.size();
5        int l = 0;
6        char curr = chars[0];
7        int cnt = 1;
8
9        for(int i = 1; i < n; i++) {
10            if(chars[i] != curr) {
11                if(cnt == 1) {
12                    chars[l] = curr;
13                    l++;
14                } else {
15                    string s = to_string(cnt);
16                    chars[l] = curr;
17                    l++;
18                    for(char c : s) {
19                        chars[l] = c;
20                        l++;
21                    }
22                    cnt = 1;
23                }
24                curr = chars[i];
25            } else {
26                cnt++;
27            }
28        }
29        if(cnt > 1) {
30            chars[l] = curr;
31            l++;
32            string s = to_string(cnt);
33                   
34            for(char c : s) {
35                chars[l] = c;
36                l++;
37            }
38        } else {
39            chars[l] = curr;
40            l++;
41        }
42        
43        return l;
44    }
45};