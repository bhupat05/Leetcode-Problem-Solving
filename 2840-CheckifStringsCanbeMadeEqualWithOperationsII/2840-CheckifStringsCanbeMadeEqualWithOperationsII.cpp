// Last updated: 3/30/2026, 10:14:34 AM
1class Solution {
2public:
3    bool checkStrings(string s1, string s2) {
4        int n = s1.size();
5        vector<int> e1(26, 0);
6        vector<int> e2(26, 0);
7        vector<int> o1(26, 0);
8        vector<int> o2(26, 0);
9
10        for(int i = 0; i < n; i++) {
11            if(i % 2 == 0) {
12                e1[s1[i] - 'a']++;
13                e2[s2[i] - 'a']++;
14            } else {
15                o1[s1[i] - 'a']++;
16                o2[s2[i] - 'a']++;
17            }
18        }
19
20        return e1 == e2 && o1 == o2;
21    }
22};