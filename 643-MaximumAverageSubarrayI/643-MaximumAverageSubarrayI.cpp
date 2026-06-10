// Last updated: 6/10/2026, 4:32:43 PM
1class Solution {
2public:
3    bool help(char c) {
4        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
5           c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
6            return true;
7           }
8        return false;
9    }
10    int maxVowels(string s, int k) {
11        int n = s.size();
12        int ans = 0;
13        int curr = 0;
14        int l = 0;
15
16        for(int i = 0; i < k; i++) {
17            if(help(s[i])) {
18                curr++;
19            }
20        }
21        ans = curr;
22
23        for(int i = k; i < n; i++) {
24            curr += (help(s[i]) ? 1 : 0) - (help(s[l]) ? 1 : 0);
25            ans = max(ans, curr);
26            l++;
27        }
28        return ans;
29    }
30};