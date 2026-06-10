// Last updated: 6/10/2026, 7:32:47 AM
1class Solution {
2public:
3    string mergeAlternately(string word1, string word2) {
4        int m = word1.size();
5        int n = word2.size();
6        string r = "";
7        int i = 0, j = 0;
8
9        while(i < m && j < n) {
10            r += word1[i];
11            r += word2[j];
12            i++;
13            j++;
14        }
15        while(i < m) {
16            r += word1[i];
17            i++;
18        }
19        while(j < n) {
20            r += word2[j];
21            j++;
22        }
23        return r;
24    }
25};