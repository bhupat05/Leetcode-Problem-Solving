// Last updated: 5/27/2026, 10:23:13 AM
1class Solution {
2public:
3    int numberOfSpecialChars(string word) {
4        int n = word.size();
5        int cnt = 0;
6
7        vector<int> lower(26, -1);
8        vector<int> upper(26, -1);
9
10        for(int i = 0; i < n; i++) {
11            if(word[i] >= 'A' && word[i] <= 'Z') {
12                if(upper[word[i] - 'A'] == -1)
13                    upper[word[i] - 'A'] = i;
14            } 
15            else {
16                lower[word[i] - 'a'] = i;
17            }
18        }
19
20        for(int i = 0; i < 26; i++) {
21            if(lower[i] != -1 && upper[i] != -1 && lower[i] < upper[i])
22                cnt++;
23        }
24
25        return cnt;
26    }
27};