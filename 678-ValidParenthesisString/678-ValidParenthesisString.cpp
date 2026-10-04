// Last updated: 10/4/2026, 2:04:22 PM
1class Solution {
2public:
3    bool checkValidString(string s) {
4        int n = s.length();
5
6        int open = 0;
7        int close = 0;
8
9        for(int i = 0; i < n; i++){
10            if(s[i] == '(' || s[i] == '*'){
11                open++;
12            }else{
13                open--;
14            }
15            if(open < 0){
16                return false;
17            }
18        }
19
20        for(int i = n - 1; i >= 0; i--){
21            if(s[i] == ')' || s[i] == '*'){
22                close++;
23            }else{
24                close--;
25            }
26            if(close < 0){
27                return false;
28            }
29        }
30
31        return true;
32    }
33};