// Last updated: 5/26/2026, 7:38:26 AM
1class Solution {
2public:
3    int numberOfSpecialChars(string word) {
4        int n = word.size();
5        int cnt = 0;
6
7        vector<int> a(26, 0);
8        vector<int> b(26, 0);
9
10        for(int i = 0; i < n; i++) {
11            if(word[i] >= 'A' && word[i] <= 'Z') {
12                b[word[i] + 32 - 'a']++;
13            } else {
14                a[word[i] - 'a']++;
15            }
16        }
17        for(int i = 0; i < 26; i++) {
18            if(a[i] && b[i]) cnt++;
19        }
20        return cnt;
21        
22    }
23};