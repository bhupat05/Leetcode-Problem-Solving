// Last updated: 3/29/2026, 7:57:32 AM
1class Solution {
2public:
3    bool canBeEqual(string s1, string s2) {
4
5        if(s1 == s2) return true;
6
7        swap(s1[0], s1[2]);
8
9        if(s1 == s2) return true;
10
11        swap(s1[1], s1[3]);
12
13        if(s1 == s2) return true;
14        swap(s1[0], s1[2]);
15        if(s1 == s2) return true;
16
17        return false;
18        
19
20
21
22        
23    }
24};