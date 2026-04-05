// Last updated: 4/5/2026, 8:36:34 AM
1class Solution {
2public:
3    int mirrorFrequency(string s) {
4        vector<int> v1(26, 0);
5        vector<int> v2(10, 0);
6        
7
8        for(char c : s) {
9            if(c >= '0' && c <= '9') {
10                v2[c - '0']++;
11            } else {
12               v1[c - 'a']++; 
13            }
14            
15        }
16
17        int ans = 0;
18
19        for(int i = 0; i < 13; i++) {
20            ans += abs(v1[i] - v1[26 - i - 1]);
21        
22        }
23        for(int i = 0; i < 5; i++) {
24            ans += abs(v2[i] - v2[9 - i ]);
25        }
26
27
28        return ans;
29        
30    }
31};