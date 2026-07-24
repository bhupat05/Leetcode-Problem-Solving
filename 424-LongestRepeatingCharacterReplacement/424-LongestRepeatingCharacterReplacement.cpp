// Last updated: 7/24/2026, 10:15:40 AM
1class Solution {
2public:
3    int characterReplacement(string s, int k) {
4        int n = s.length();
5
6        int l = 0;
7        int r = 0;
8        int maxlen = 0, maxf = 0;
9        vector<int>count(26, 0);
10
11        while(r < n){
12            count[s[r] - 'A']++;
13            maxf = max(maxf, count[s[r] - 'A']);
14
15            while((r - l + 1) - maxf > k){
16                count[s[l] - 'A']--;
17                l++;
18            }
19
20            maxlen = max(maxlen, r - l + 1);
21            r++;
22        }
23
24        return maxlen;
25
26
27    }
28};