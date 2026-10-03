// Last updated: 10/3/2026, 9:05:27 AM
1class Solution {
2public:
3    int longestValidParentheses(string s) {
4        int l=0;
5        int r=0;
6        int max_l=0;
7        for(int i=0; i<s.length(); i++){
8            if(s[i] == '(')
9            l++;
10            else
11            r++;
12            if(l == r){
13                max_l = max(max_l,2*l);
14            }
15            else if(r>l)
16           {
17             l=0;
18            r=0;
19           }
20        }
21        l=0;
22        r=0;
23         for(int i=s.length()-1; i>=0; i--){
24            if(s[i] == '(')
25            l++;
26            else
27            r++;
28            if(l == r){
29                max_l = max(max_l,2*l);
30            }
31            else if(r<l)
32           {
33             l=0;
34            r=0;
35           }
36        }
37        return max_l;
38        
39    }
40};