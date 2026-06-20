// Last updated: 6/20/2026, 3:09:50 PM
1class Solution {
2public:
3    bool closeStrings(string word1, string word2) {
4        int m = word1.size();
5        int n = word2.size();
6        vector<int> v1(26, 0);
7        vector<int> v2(26, 0);
8
9        for(char c : word1) {
10            v1[c - 'a']++;
11        }
12        for(char c : word2) {
13            v2[c - 'a']++;
14        }
15
16        for(int i = 0; i < 26; i++) {
17            if((v1[i] && !v2[i]) || (!v1[i] && v2[i])) {
18                return false;
19                cout << 1 << endl;
20            }
21        }
22        sort(v1.begin(), v1.end());
23        sort(v2.begin(), v2.end());
24
25        for(int i = 0; i < 26; i++) {
26            if(v1[i] != v2[i]) return false;
27        }
28        return true;
29    }
30};