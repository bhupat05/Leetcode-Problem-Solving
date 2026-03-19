// Last updated: 3/19/2026, 10:59:22 AM
1class Solution {
2public:
3    string intToRoman(int num) {
4        map<int, string, greater<int>> mp = {
5            {1, "I"},
6            {5, "V"},
7            {10, "X"},
8            {50, "L"},
9            {100, "C"},
10            {500, "D"},
11            {1000, "M"},
12            {4, "IV"},
13            {9, "IX"},
14            {40, "XL"},
15            {90, "XC"},
16            {400, "CD"},
17            {900, "CM"}
18
19        };
20
21        string r = "";
22
23            for(auto &it : mp) {
24                while(it.first <= num) {
25                    num -= it.first;
26                    r += it.second;
27                }
28            }
29        
30        return r;
31    }
32};